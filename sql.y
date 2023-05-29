%{
#include "sql.h"

char database[64]={0};

int yylex();
int yyparse();

void yyerror (const char *str) 
{
	fprintf(stderr, "error: %s\n", str);		// error function
}

int yywrap() 
{
	return 1;
}
// main function 
int main() 
{
	printf("SQL>");
	return	yyparse(); // calling parse funtion 
} 

%}

%union{  
	int intval;   
	double dval;
  	char *strval;
  	struct hyper_items_def *Citemsval;
  	struct value_def *valueval;
  	struct item_def *itemval;
  	struct conditions_def *conval;
  	struct table_def *tbval;
  	struct upcon_def *updateval;
}

%token SELECT FROM WHERE AND OR DROP DELETE TABLE CREATE INTO VALUES INSERT UPDATE SET SHOW DATABASE DATABASES TABLES EXIT USE
%token <intval> NUMBER 
%token <strval> STRING ID INT CHAR DOUBLE
%token <dval> DOUBLEN
%type <intval> comparator
%type <Citemsval> hyper_items create_items
%type <valueval> value_list value
%type <itemval> item item_list
%type <conval> condition conditions
%type <tbval> tables
%type <updateval> up_cond up_conds
%left OR
%left AND


%%

/* production for sql grammar */

statements: statements statement | statement 
statement: createsql | showsql | selectsql | insertsql | deletesql | updatesql | dropsql | exitsql | usesql | nextsql

nextsql:		'\n' {printf("SQL>");}

usesql: 		USE ID ';' '\n' {
					useDB($2);
		        }

showsql: 		SHOW DATABASES ';' '\n' {
		            showDB();
		        }
		        |SHOW TABLES ';' '\n' {
		            showTable();
		        }

createsql:		CREATE TABLE ID '(' hyper_items ')' ';' '\n' {//sql创建语句
                	createTable($3, $5);
				}

				|CREATE DATABASE ID ';' '\n' {
					strcpy(database, $3);
					createDB();
				}		        

selectsql: 		SELECT '*' FROM tables ';' '\n'{
					selectWhere(NULL, $4, NULL);
					printf("\n");
				}
				| SELECT item_list FROM tables ';' '\n' {
					selectWhere($2, $4, NULL);
				}		
				|SELECT '*' FROM tables WHERE conditions ';' '\n' {
					selectWhere(NULL, $4, $6);
				}
				|SELECT item_list FROM tables WHERE conditions ';' '\n' { 
					selectWhere($2, $4, $6);
				}

deletesql:		DELETE FROM ID ';' '\n' {
					deletes($3, NULL);
				}

				|DELETE FROM ID WHERE conditions ';' '\n' 	{ 
					deletes($3, $5);
				}


insertsql:		INSERT INTO ID VALUES '(' value_list ')' ';' '\n' {//sql插入语句
					multiInsert($3, NULL, $6);
				}
		
				|INSERT INTO ID '(' item_list ')' VALUES '(' value_list ')' ';' '\n' {
					multiInsert($3, $5, $9);
				}


updatesql:		UPDATE ID SET up_conds ';' '\n' {
					updates($2, $4, NULL);
				}
		
				|UPDATE ID SET up_conds WHERE conditions ';' '\n' {
					updates($2, $4, $6);
				}

dropsql:		DROP TABLE ID ';' '\n'	{
					dropTable($3);
				}
				| DROP DATABASE ID ';' '\n' {
					dropDB($3);
				}

exitsql: 		EXIT ';' {
		            printf("exit with code 0!\n");
		            exit(0);
		        }

create_items:	ID INT {//该生成试返回一个结构体
					$$ = (struct hyper_items_def *)malloc(sizeof(struct hyper_items_def));
                    $$->field = $1;
                    $$->type = 0;	
                    $$->next = NULL;	
				}
				| ID DOUBLE {
					$$ = (struct hyper_items_def *)malloc(sizeof(struct hyper_items_def));
                    $$->field = $1;
                    $$->type = 1;
                    $$->next = NULL;	
				}
				| ID CHAR '(' NUMBER ')'{
					$$ = (struct hyper_items_def *)malloc(sizeof(struct hyper_items_def));
                    $$->field = $1;
                    $$->type = 2;
                    $$->next = NULL;	
				}
				

hyper_items: 	create_items {
					$$ = $1;
				}
				| hyper_items ',' create_items {//创建一个属性链表，这里左递归，属性值逆序了
					$$ = $3;
					$$->next = $1;				
				}

item: 			ID {
					$$ = (struct item_def *)malloc(sizeof(struct item_def));
					$$->field = $1;
					$$->pos = NULL;
					$$->next = NULL;
				}

item_list: 		item {
					$$ = $1;				
				}
				| item_list ',' item{//产生一个只有字段组成的链表
					$$ = $3;
					$$->next = $1;
				}

value:			NUMBER {
					$$ = ((struct value_def *)malloc(sizeof(struct value_def)));
					$$->value.intkey = $1;
					$$->type = 0;
					$$->next = NULL;
				}
				| DOUBLEN {
					$$ = ((struct value_def *)malloc(sizeof(struct value_def)));
					$$->value.dkey = $1;
					$$->type = 1;
					$$->next = NULL;
				}
				| STRING {
					$$ = ((struct value_def *)malloc(sizeof(struct value_def)));
					strcpy($$->value.skey, $1);
					$$->type = 2;
					$$->next = NULL;
				}

value_list:		value {
					$$ = $1;
				}
				| value_list ',' value {//值列表
					$$ = $3;
					$$->next = $1;
				}

comparator:		'=' {$$ = 1; }//终结符
				| '>' {$$ = 2; }
				| '<' {$$ = 3; }
				| ">=" {$$ = 4; }
				| "<=" {$$ = 5; }
				| '!' '=' {$$ = 6; }

condition: 		item comparator NUMBER {
					$$ = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					$$->type = 0;
					$$->litem = $1;
					$$->intv = $3;
					$$->cmp_op = $2;
					$$->left = NULL;
					$$->right = NULL;
				}
				| item comparator DOUBLEN {
					$$ = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					$$->type = 1;
					$$->litem = $1;
					$$->intv = $3;
					$$->cmp_op = $2;
					$$->left = NULL;
					$$->right = NULL;
				}
				| item comparator STRING {
					$$ = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					$$->type = 2;
					$$->litem = $1;
					$$->strv = $3;
					$$->cmp_op = $2;
					$$->left = NULL;
					$$->right = NULL;
				}

conditions: 	condition {
					$$ = $1;
				}
				|'(' conditions ')' {
					$$ = $2;
				}
				| conditions AND conditions {
					$$ = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					$$->cmp_op = 7;
					$$->left = $1;
					$$->right = $3;
				}
				| conditions OR conditions {
					$$ = ((struct conditions_def *)malloc(sizeof(struct conditions_def)));
					$$->cmp_op = 8;
					$$->left = $1;
					$$->right = $3;
				}

tables:			ID {
					$$ = ((struct table_def *)malloc(sizeof(struct table_def)));
					$$->table = $1;
					$$->next = NULL;
				}
				| tables ',' ID{
					$$ = ((struct table_def *)malloc(sizeof(struct table_def)));
					$$->table = $3;
					$$->next = $1;				
				}

up_cond:		ID '=' NUMBER {
					$$ = ((struct upcon_def *)malloc(sizeof(struct upcon_def)));
					$$->field = $1;
					$$->type = 0;
					$$->value.intkey = $3;
					$$->next = NULL;
				}
				| ID '=' DOUBLEN {
					$$ = ((struct upcon_def *)malloc(sizeof(struct upcon_def)));
					$$->field = $1;
					$$->type = 1;
					$$->value.dkey = $3;
					$$->next = NULL;				
				}
				| ID '=' STRING {
					$$ = ((struct upcon_def *)malloc(sizeof(struct upcon_def)));
					$$->field = $1;
					$$->type = 1;
					strcpy($$->value.skey, $3);
					$$->next = NULL;				
				}

up_conds:		up_cond {
					$$ = $1;
				}
				| up_conds ',' up_cond {
					$$ = $3;
					$$->next = $1;
				}

%%
