#include "sql.h"

#define TRUE 1
#define FALSE 0

extern char database[64];

struct mydb *dbroot = NULL;

/*item链表就地逆置*/
struct item_def *converseItems(struct item_def *ppHead)
{
	struct item_def *pCurNode = ppHead;
	struct item_def *pPrevNode = NULL;
	struct item_def *pTmpNode = NULL;
	while (pCurNode)
	{
		pPrevNode = pCurNode;
		pCurNode = pCurNode->next;
		pPrevNode->next = pTmpNode;
		pTmpNode = pPrevNode;
	}
	return pTmpNode;
}

/*各种结构链表的内存释放*/
void freeHItems(struct hyper_items_def *Hitemroot)
{
	struct hyper_items_def *Hitemtemp;
	while (Hitemroot != NULL)
	{
		Hitemtemp = Hitemroot->next;
		free(Hitemroot);
		Hitemroot = Hitemtemp;
	}
}

void freeCons(struct conditions_def *conroot)
{
	if (conroot == NULL)
		return;
	if (conroot->left != NULL)
		freeCons(conroot->left);
	else if (conroot->right != NULL)
		freeCons(conroot->right);
	else
		free(conroot);
}

void freeItems(struct item_def *itemroot)
{
	struct item_def *itemtemp;
	while (itemroot != NULL)
	{
		itemtemp = itemroot->next;
		free(itemroot);
		itemroot = itemtemp;
	}
}

void freeTables(struct table_def *tableroot)
{
	struct table_def *tableptr;
	while (tableroot != NULL)
	{
		tableptr = tableroot->next;
		free(tableroot);
		tableroot = tableptr;
	}
}

void freeTable(struct table *tableroot)
{
	struct table *tableptr;
	while (tableroot != NULL)
	{
		tableptr = tableroot->next;
		free(tableroot);
		tableroot = tableptr;
	}
}

void freeUpcon(struct upcon_def *uproot)
{
	struct upcon_def *uptemp;
	while (uproot != NULL)
	{
		uptemp = uproot->next;
		free(uptemp);
		uproot = uptemp;
	}
}

void freeVal(struct value_def *valroot)
{
	struct value_def *valtemp;
	while (valroot != NULL)
	{
		valtemp = valroot->next;
		free(valroot);
		valroot = valtemp;
	}
}

/*创建数据库。若数据库根节点为空，则在根结点处创建数据库，若不为空则遍历数据库链表，
若找到同名数据库，提示已存在，返回，若没找到，在链表尾部插入新的数据库*/
void createDB()
{
	if (dbroot == NULL)
	{
		dbroot = (struct mydb *)malloc(sizeof(struct mydb));
		strcpy(dbroot->name, database);
		dbroot->tbroot = NULL;
		dbroot->next = NULL;
		if (dbroot != NULL)
			;
		printf("Database %s created successfully!\n...\nSQL>", database);
		return;
	}
	struct mydb *newdb;
	newdb = dbroot;
	while (newdb->next != NULL) // 找到最后一个数据库链表的终点，顺便看看这个名字的数据库是不是已经创建了
	{
		if (strcmp(newdb->name, database) == 0)
		{
			printf("error: The database already exists!\n...\nSQL>");
			return;
		}
		newdb = newdb->next;
	}
	if (strcmp(newdb->name, database) == 0)
	{
		printf("error: The database already exists!\n...\nSQL>");
		return;
	} // 新建数据库
	newdb->next = (struct mydb *)malloc(sizeof(struct mydb));
	strcpy(newdb->next->name, database);
	newdb->next->tbroot = NULL;
	newdb->next->next = NULL;
	if (dbroot->next != NULL)
		;
	printf("Database %s created successfully!\n...\nSQL>", database);
}

/*展示所有数据库。若根节点为空，提示数据库列表为空请先创建一个数据库，否则遍历数据库链表，打印数据库名*/
void showDB()
{
	struct mydb *dbtemp = NULL;
	if (dbroot != NULL)
		dbtemp = dbroot;
	else
	{
		printf("Database list is NULL, Please create a database first!\n...\nSQL>");
		return;
	}
	while (dbtemp != NULL)
	{
		printf("%s  ", dbtemp->name);
		dbtemp = dbtemp->next;
	}
	printf("\n...\nSQL>");
}

/*指定使用的数据库，若数据库根节点为空，提示请先创建一个数据库，遍历数据库链表，找到对应数据库，
将全局变量database更新为当前数据库名，否则提示数据库不存在，返回*/
void useDB(char *dbname)
{
	struct mydb *dbtemp = NULL;
	if (dbroot != NULL)
		dbtemp = dbroot;
	else
	{
		printf("error: Please create a database first!\n...\nSQL>");
		return;
	}
	while (dbtemp != NULL)
	{
		if (strcmp(dbtemp->name, dbname) == 0)
		{
			strcpy(database, dbname);
			printf("Using database %s\n", dbname);
			return;
		}
		dbtemp = dbtemp->next;
	}
	printf("error: Database %s doesn't exist!\n...\nSQL>", dbname);
}

/*创建表。若数据库根节点为空，提示先创建数据库，否则遍历数据库列表，查找当前使用的数据库，若未找到，提示数据库不存在，
若找到，再看当前数据库下的表根节点是否为空，若为空，在根节点处创建新表，否则遍历表链表，若找到名字相同的表，提示
该表已存在，返回，否则在链表尾部建立新表*/
void createTable(char *tableval, struct hyper_items_def *Hitemroot)
{
	int i;
	struct mydb *dbtemp = NULL;
	struct table *newtable = NULL;
	struct table *tabletemp = NULL;
	struct hyper_items_def *itemstemp = Hitemroot;
	if (dbroot != NULL) // 如果根节点为空则需要先创建数据库
		dbtemp = dbroot;
	else
	{
		printf("error: Please create a database first!\n...\nSQL>");
		freeHItems(Hitemroot); // 销毁属性列表
		return;
	}
	while (dbtemp != NULL)
	{
		if (strcmp(dbtemp->name, database) == 0) // 找到当前数据库
		{
			if (dbtemp->tbroot == NULL) // 如果该数据库还没有表，则要创建的是第一个表
			{
				dbtemp->tbroot = (struct table *)malloc(sizeof(struct table));
				strcpy(dbtemp->tbroot->name, tableval);										// 给表儿起个名儿
				dbtemp->tbroot->ffield = (struct field *)malloc(10 * sizeof(struct field)); // 简单点，最多10个字段，每个字段100个数据项
				i = 0;
				while (itemstemp != NULL && i < 10) // 遍历属性列表，最多录入前10个属性
				{
					strcpy(dbtemp->tbroot->ffield[i].name, itemstemp->field); // 将语句中的字段名，赋值给内存中的数据表名
					if (itemstemp->type == 0)								  // 赋值类型
						dbtemp->tbroot->ffield[i].type = 0;
					else if (itemstemp->type == 1)
						dbtemp->tbroot->ffield[i].type = 1;
					else
						dbtemp->tbroot->ffield[i].type = 2;
					itemstemp = itemstemp->next;
					i++;
				}
				dbtemp->tbroot->flen = i; // 有i个字段
				dbtemp->tbroot->ilen = 0; // 目前有0条记录
				dbtemp->tbroot->next = NULL;
				if (dbtemp->tbroot != NULL)
					printf("Table %s created successfully!\n...\nSQL>", tableval);
				freeHItems(Hitemroot); // 释放负责传值的链表
				return;
			}
			newtable = dbtemp->tbroot; // 指针指向表根节点，开始扫描到尾，如果已经存在这个表，就报错
			while (newtable->next != NULL)
			{
				if (strcmp(newtable->name, tableval) == 0)
				{
					printf("error: The table already exists!\n...\nSQL>");
					freeHItems(Hitemroot);
					return;
				}
				newtable = newtable->next;
			}
			if (strcmp(newtable->name, tableval) == 0)
			{
				printf("error: The table already exists!\n...\nSQL>");
				freeHItems(Hitemroot);
				return;
			}
			newtable->next = (struct table *)malloc(sizeof(struct table)); // 申请内存
			strcpy(newtable->next->name, tableval);
			newtable->next->ffield = (struct field *)malloc(10 * sizeof(struct field));
			i = 0;
			while (itemstemp != NULL && i < 10)
			{
				strcpy(newtable->next->ffield[i].name, itemstemp->field);
				if (itemstemp->type == 0)
					newtable->next->ffield[i].type = 0;
				else if (itemstemp->type == 1)
					newtable->next->ffield[i].type = 1;
				else
					newtable->next->ffield[i].type = 2;
				itemstemp = itemstemp->next;
				i++;
			}
			newtable->next->flen = i;
			newtable->next->ilen = 0;
			newtable->next->next = NULL;
			printf("Table %s created successfully!\n...\nSQL>", tableval);
			freeHItems(Hitemroot);
			return;
		}
		dbtemp = dbtemp->next;
	}
	freeHItems(Hitemroot);
	printf("error: Database %s doesn't exist!\n...\nSQL>", database);
}

/*展示表。遍历当前选用的数据库下的表链表，打印表名*/
void showTable()
{
	struct mydb *dbtemp = NULL;
	struct table *tabletemp = NULL;
	int i, j, temp;
	if (dbroot != NULL)
		dbtemp = dbroot;
	else
	{
		printf("error: Please create a database first!\n...\nSQL>");
		return;
	}
	while (dbtemp != NULL)
	{
		if (strcmp(dbtemp->name, database) == 0)
		{
			tabletemp = dbtemp->tbroot;
			while (tabletemp != NULL)
			{
				printf("%s  ", tabletemp->name);
				tabletemp = tabletemp->next;
			}
			printf("\n...\nSQL>");
			return;
		}
		dbtemp = dbtemp->next;
	}
	printf("error: Database %s doesn't exist!\n...\nSQL>", database);
}

/*插入记录。找到插入的表，若未找到，提示不存在，找到以后，若未指定字段及其顺序，将value list中的值依次插入到每个字段的最后，
若指定了字段和顺序，则按顺序查找字段，并依次追加记录，若未查找到对应字段，则提示字段与表不匹配，返回。完成插值以后，
判断itemlist和valuelist是否同时为空，若不是，则提示两者不匹配，返回，若是，则提示成功，并将该表的条数值加一*/
void multiInsert(char *tableval, struct item_def *itemroot, struct value_def *valroot)
{
	struct mydb *dbtemp = NULL;
	struct table *tabletemp = NULL;
	struct item_def *itemtemp = NULL;
	struct value_def *valtemp = NULL;
	int i, j, temp;
	if (dbroot != NULL)
		dbtemp = dbroot;
	else
	{
		printf("error: Please create a database first!\n...\nSQL>");
		freeItems(itemroot);
		freeVal(valroot);
		return;
	}
	while (dbtemp != NULL)
	{
		if (strcmp(dbtemp->name, database) == 0) // 找到数据库
		{
			tabletemp = dbtemp->tbroot;
			while (tabletemp != NULL)
			{
				if (strcmp(tabletemp->name, tableval) == 0) // 找到表
				{
					i = 0;
					temp = tabletemp->ilen; // 得到行数
					valtemp = valroot;		// 得到值列表
					if (itemroot == NULL)	// 默认的插入语句，没有属性名
					{
						while (valtemp != NULL) // 遍历值列表
						{
							if (valtemp->type != tabletemp->ffield[i].type)
							{
								printf("error: Type mismatch!\n...\nSQL>");
								freeItems(itemroot);
								freeVal(valroot);
								return;
							}
							if (valtemp->type == 0) // 如果为整形就把整形数值附近去，反之赋值字符串类型，注意这里是运用了union
							{
								tabletemp->ffield[i].type = 0;
								tabletemp->ffield[i].key[temp].intkey = valtemp->value.intkey;
							}
							else if (valtemp->type == 1)
							{
								tabletemp->ffield[i].type = 1;
								tabletemp->ffield[i].key[temp].dkey = valtemp->value.dkey;
							}
							else
							{
								tabletemp->ffield[i].type = 2;
								strcpy(tabletemp->ffield[i].key[temp].skey, valtemp->value.skey);
							}
							i++; // 记录目前加了几个属性
							valtemp = valtemp->next;
						}
					}
					else // 有列表的
					{
						itemtemp = itemroot;
						while (itemtemp != NULL && valtemp != NULL)
						{
							for (j = 0; j < tabletemp->flen; j++)
							{
								if (strcmp(tabletemp->ffield[j].name, itemtemp->field) == 0) // 找到了这个字段
								{
									if (valtemp->type != tabletemp->ffield[j].type)
									{
										printf("error: Type mismatch!\n...\nSQL>");
										freeItems(itemroot);
										freeVal(valroot);
										return;
									}
									if (valtemp->type == 0)
									{
										tabletemp->ffield[j].type = 0;
										tabletemp->ffield[j].key[temp].intkey = valtemp->value.intkey;
									}
									else if (valtemp->type == 1)
									{
										tabletemp->ffield[j].type = 1;
										tabletemp->ffield[j].key[temp].dkey = valtemp->value.dkey;
									}
									else
									{
										tabletemp->ffield[j].type = 2;
										strcpy(tabletemp->ffield[j].key[temp].skey, valtemp->value.skey);
									}
									i++; // 记录插入了几个值
									break;
								}
							}
							if (j == tabletemp->flen) // j走到最后一个也没找完，前面的如果能赋值上还是会赋值上的
							{
								printf("error: Column name does not match the table definition!\n...\nSQL>");
								freeItems(itemroot);
								freeVal(valroot);
								return;
							}
							itemtemp = itemtemp->next; // 找下一个传过来的字段
							valtemp = valtemp->next;
						}
					}
					if (i <= tabletemp->flen && itemtemp == NULL && valtemp == NULL) // 数量是否匹配的判定
					{
						temp++; // 行数加一
						tabletemp->ilen = temp;
						printf("Insert successfully!\n...\nSQL>");
					}
					else
					{
						printf("error: The number of supplied values does not match the table definition!\n...\nSQL>");
					}
					freeItems(itemroot);
					freeVal(valroot);
					return;
				}
				tabletemp = tabletemp->next;
			}
			printf("error: The table doesn't exist!\n...\nSQL>");
			freeItems(itemroot);
			freeVal(valroot);
			return;
		}
		dbtemp = dbtemp->next;
	}
	freeItems(itemroot);
	freeVal(valroot);
	printf("error: Database %s doesn't exist!\n...\nSQL>", database);
}

/*二叉树递归判断条件正误，i是当前判断的一条记录在表中的位置索引，tabletemp是用于判断的临时表，单表查询时它指向单表，
多表查询时它是多表的笛卡尔乘积，conroot是条件二叉树根节点，当conroot为空时直接判断为TRUE，这个主要用于无条件的查询和更新，
删除等操作，有条件时，即最初传入的conroot不为空时，不会触发这条判断执行*/
_Bool whereTF(int i, struct table *tabletemp, struct conditions_def *conroot)
{
	if (conroot == NULL)
	{
		return TRUE;
	}
	if (conroot->cmp_op == 7)
	{
		return whereTF(i, tabletemp, conroot->left) && whereTF(i, tabletemp, conroot->right);
	}
	else if (conroot->cmp_op == 8)
	{
		return whereTF(i, tabletemp, conroot->left) || whereTF(i, tabletemp, conroot->right);
	}
	else
	{
		if (conroot->litem->pos == NULL)
		{
			int k;
			for (k = 0; k < tabletemp->flen; k++)
			{
				if (strcmp(tabletemp->ffield[k].name, conroot->litem->field) == 0)
				{
					conroot->litem->pos = &tabletemp->ffield[k];
					break;
				}
			}
			if (conroot->litem->pos == NULL)
			{
				printf("error: 	Field %s doesn't exist!\n...\nSQL>", conroot->litem->field);
				return FALSE;
			}
		}
		if (conroot->cmp_op == 1)
		{
			if (conroot->type == 0)
				return conroot->litem->pos->key[i].intkey == conroot->intv;
			else if (conroot->type == 1)
				return conroot->litem->pos->key[i].dkey == conroot->intv;
			else
				return strcmp(conroot->litem->pos->key[i].skey, conroot->strv) == 0;
		}
		else if (conroot->cmp_op == 2)
		{
			if (conroot->type == 0)
			{
				return conroot->litem->pos->key[i].intkey > conroot->intv;
			}
			else if (conroot->type == 1)
			{
				return conroot->litem->pos->key[i].dkey > conroot->intv;
			}
			else
			{
				printf("error: String can not compare!\n...\nSQL>");
				return FALSE;
			}
		}
		else if (conroot->cmp_op == 3)
		{
			if (conroot->type == 0)
				return conroot->litem->pos->key[i].intkey < conroot->intv;
			else if (conroot->type == 1)
				return conroot->litem->pos->key[i].dkey < conroot->intv;
			else
			{
				printf("error: String can not compare!\n...\nSQL>");
				return FALSE;
			}
		}
		else if (conroot->cmp_op == 4)
		{
			if (conroot->type == 0)
				return conroot->litem->pos->key[i].intkey >= conroot->intv;
			else if (conroot->type == 1)
				return conroot->litem->pos->key[i].dkey >= conroot->intv;
			else
			{
				printf("error: String can not compare!\n...\nSQL>");
				return FALSE;
			}
		}
		else if (conroot->cmp_op == 5)
		{
			if (conroot->type == 0)
				return conroot->litem->pos->key[i].intkey <= conroot->intv;
			else if (conroot->type == 1)
				return conroot->litem->pos->key[i].dkey <= conroot->intv;
			else
			{
				printf("error: String can not compare!\n...\nSQL>");
				return FALSE;
			}
		}
		else
		{
			if (conroot->type == 0)
				return conroot->litem->pos->key[i].intkey != conroot->intv;
			else if (conroot->type == 1)
				return conroot->litem->pos->key[i].dkey != conroot->intv;
			else
				return strcmp(conroot->litem->pos->key[i].skey, conroot->strv) != 0;
		}
	}
}

void printtable(struct table *tabletemp)
{
	for (int j = 0; j < tabletemp->flen; j++)
	{
		printf("%-20s  ", tabletemp->ffield[j].name);
	}
	printf("\n");
}

/*查询操作，目前仅支持多个表查询。itemroot是选择的字段链表根节点，若为*即全选则传入NULL，tableroot是选择的表根节点，
conroot是条件二叉树根节点，若无条件则传入NULL，首先找到查询的表，找到以后更新每个table_def结构的pos变量，指向对应的表，
然后判断是否是单表，若为单表，tabletemp指向该表，再判断itemroot是否为空，若为空表示全选，依次将整个表打印出来，
提示成功，返回。若不为单表，即为2个表联合查询，那么先遍历两个表，找到第一组名称相同且数据类型相同的字段，作为主码，
将字段值相同的记录进行合并，构成新表，存入tabletemp中，若没有字段相同的，将笛卡尔乘积存入tabletemp中，然后判断itemroot
是否为空，若为空，判断并打印所有字段记录，若不为空，判断并打印对应的字段记录*/
void selectWhere(struct item_def *itemroot, struct table_def *tableroot, struct conditions_def *conroot)
{
	struct mydb *dbtemp = NULL;
	struct table_def *tableptr = NULL;
	struct table *tabletemp = NULL;
	struct item_def *itemtemp = NULL;
	int i, j, k, m, n, len1, len2;
	itemroot = converseItems(itemroot);
	if (dbroot != NULL)
		dbtemp = dbroot;
	else
	{
		printf("error: Please create a database first!\n...\nSQL>");
		freeCons(conroot);
		freeItems(itemroot);
		freeTables(tableroot);
		return;
	}
	while (dbtemp != NULL)
	{
		if (strcmp(dbtemp->name, database) == 0) // 找到数据库
		{
			tableptr = tableroot;
			while (tableptr != NULL)
			{
				tabletemp = dbtemp->tbroot; // 内存中的表的地址
				while (tabletemp != NULL)
				{
					if (strcmp(tabletemp->name, tableptr->table) == 0)
					{
						tableptr->pos = tabletemp; // 请求表列表的指针指向内存中表的地址
						break;
					}
					tabletemp = tabletemp->next;
				}
				if (tabletemp == NULL)
				{
					printf("error: 	Table %s doesn't exist!\n...\nSQL>", tableptr->table);
					freeCons(conroot);
					freeItems(itemroot);
					freeTables(tableroot);
					return;
				}
				tableptr = tableptr->next;
			}
			if (tableroot->next == NULL) // 如果是单表
			{
				tabletemp = tableroot->pos; // 找到想要请求的这个表
				if (itemroot == NULL)		// 选中所有列，全部打印
				{
					for (j = tabletemp->flen - 1; j >= 0; j--) // 语句传值的时候是逆序传值 插入的时候是正序的 因此最后是逆序
					{
						printf("%-20s  ", tabletemp->ffield[j].name); // 打印表头
					}
					printf("\n");
					for (i = 0; i < tabletemp->ilen; i++) // 按行打印表中数据
					{
						if (whereTF(i, tabletemp, conroot) == TRUE)
						{
							for (j = tabletemp->flen - 1; j >= 0; j--)
							{
								if (tabletemp->ffield[j].type == 0)
									printf("%-20d  ", tabletemp->ffield[j].key[i].intkey);
								else if (tabletemp->ffield[j].type == 1)
									printf("%-20f  ", tabletemp->ffield[j].key[i].dkey);
								else
									printf("%-20s  ", tabletemp->ffield[j].key[i].skey);
							}
							printf("\n");
						}
					}
					freeCons(conroot);
					freeTables(tableroot);
					return;
				}
			}
			else // 多表链接
			{
				struct table_def *pCurNode = tableroot;
				struct table_def *pPrevNode = NULL;
				struct table_def *pTmpNode = NULL;
				while (pCurNode)
				{
					pPrevNode = pCurNode;
					pCurNode = pCurNode->next;
					pPrevNode->next = pTmpNode;
					pTmpNode = pPrevNode;
				}
				tableroot = pTmpNode;		  // 原地反转链表
				int fn = pTmpNode->pos->flen; // 第一个表属性的个数
				while (tableroot->next != NULL)
				{
					int pk1 = -1, pk2 = -1;
					len1 = fn;
					len2 = tableroot->next->pos->flen; // 第二个表属性的个数
					for (i = len1 - 1; i >= 0; i--)
					{
						for (j = len2 - 1; j >= 0; j--)
						{
							if (strcmp(pTmpNode->pos->ffield[i].name, tableroot->next->pos->ffield[j].name) == 0 && pTmpNode->pos->ffield[i].type == tableroot->next->pos->ffield[j].type) // 两个表的名字一致，类型一致
							{
								pk1 = i; // 记录两个表中重复列的坐标
								pk2 = j;
								break;
							}
						}
						if (strcmp(pTmpNode->pos->ffield[i].name, tableroot->next->pos->ffield[j].name) == 0 && pTmpNode->pos->ffield[i].type == tableroot->next->pos->ffield[j].type)
							break;
					}
					if (pk2 == -1) // 没有相同字段，笛卡尔积
					{
						tabletemp = (struct table *)malloc(sizeof(struct table)); // 新建了一个临时表
						tabletemp->ffield = (struct field *)malloc((len1 + len2) * sizeof(struct field));
						tabletemp->flen = len1 + len2;
						k = 0;
						for (i = len1 - 1; i >= 0; i--) // 把表头复制进去
						{
							strcpy(tabletemp->ffield[k].name, pTmpNode->pos->ffield[i].name);
							k++;
						}
						for (i = len2 - 1; i >= 0; i--)
						{
							strcpy(tabletemp->ffield[k].name, tableroot->next->pos->ffield[i].name);
							k++;
						}
						n = 0;
						for (i = 0; i < pTmpNode->pos->ilen; i++) // 把数据复制进去
						{
							for (j = 0; j < tableroot->next->pos->ilen; j++)
							{
								k = 0;
								for (m = len1 - 1; m >= 0; m--)
								{
									tabletemp->ffield[k].type = pTmpNode->pos->ffield[m].type;
									if (pTmpNode->pos->ffield[m].type == 0)
									{
										tabletemp->ffield[k].key[n].intkey = pTmpNode->pos->ffield[m].key[i].intkey;
										tabletemp->ffield[k].type = 0;
									}
									else if (pTmpNode->pos->ffield[m].type == 1)
									{
										tabletemp->ffield[k].key[n].dkey = pTmpNode->pos->ffield[m].key[i].dkey;
										tabletemp->ffield[k].type = 1;
									}
									else
									{
										strcpy(tabletemp->ffield[k].key[n].skey, pTmpNode->pos->ffield[m].key[i].skey);
										tabletemp->ffield[k].type = 2;
									}
									k++;
								}
								for (m = len2 - 1; m >= 0; m--)
								{
									tabletemp->ffield[k].type = tableroot->next->pos->ffield[m].type;
									if (tableroot->next->pos->ffield[m].type == 0)
									{
										tabletemp->ffield[k].key[n].intkey = tableroot->next->pos->ffield[m].key[j].intkey;
										tabletemp->ffield[k].type = 0;
									}
									else if (tableroot->next->pos->ffield[m].type == 1)
									{
										tabletemp->ffield[k].key[n].dkey = tableroot->next->pos->ffield[m].key[j].dkey;
										tabletemp->ffield[k].type = 1;
									}
									else
									{
										strcpy(tabletemp->ffield[k].key[n].skey, tableroot->next->pos->ffield[m].key[j].skey);
										tabletemp->ffield[k].type = 2;
									}
									k++;
								}
								n++;
							}
						}
						tabletemp->ilen = n;
					}
					else // 有相同的列，自然连接
					{
						tabletemp = (struct table *)malloc(sizeof(struct table)); // 新建了一个临时表
						tabletemp->ffield = (struct field *)malloc((len1 + len2 - 1) * sizeof(struct field));
						tabletemp->flen = len1 + len2 - 1;
						k = 0;
						for (i = len1 - 1; i >= 0; i--)
						{
							strcpy(tabletemp->ffield[k].name, pTmpNode->pos->ffield[i].name);
							k++;
						}
						for (i = len2 - 1; i >= 0; i--)
						{
							if (i == pk2)
								continue;
							strcpy(tabletemp->ffield[k].name, tableroot->next->pos->ffield[i].name);
							k++;
						}
						n = 0;
						for (i = 0; i < pTmpNode->pos->ilen; i++)
						{
							for (j = 0; j < tableroot->next->pos->ilen; j++)
							{
								if (pTmpNode->pos->ffield[pk1].type == 0 && pTmpNode->pos->ffield[pk1].key[i].intkey == tableroot->next->pos->ffield[pk2].key[j].intkey || pTmpNode->pos->ffield[pk1].type == 1 && pTmpNode->pos->ffield[pk1].key[i].dkey == tableroot->next->pos->ffield[pk2].key[j].dkey || pTmpNode->pos->ffield[pk1].type == 2 && strcmp(pTmpNode->pos->ffield[pk1].key[i].skey, tableroot->next->pos->ffield[pk2].key[j].skey) == 0)
								{
									k = 0;
									for (m = len1 - 1; m >= 0; m--)
									{
										tabletemp->ffield[k].type = pTmpNode->pos->ffield[m].type;
										if (pTmpNode->pos->ffield[m].type == 0)
										{
											tabletemp->ffield[k].key[n].intkey = pTmpNode->pos->ffield[m].key[i].intkey;
											tabletemp->ffield[k].type = 0;
										}
										else if (pTmpNode->pos->ffield[m].type == 1)
										{
											tabletemp->ffield[k].key[n].dkey = pTmpNode->pos->ffield[m].key[i].dkey;
											tabletemp->ffield[k].type = 1;
										}
										else
										{
											strcpy(tabletemp->ffield[k].key[n].skey, pTmpNode->pos->ffield[m].key[i].skey);
											tabletemp->ffield[k].type = 2;
										}
										k++;
									}
									for (m = len2 - 1; m >= 0; m--)
									{
										if (m == pk2)
											continue;
										tabletemp->ffield[k].type = tableroot->next->pos->ffield[m].type;
										if (tableroot->next->pos->ffield[m].type == 0)
										{
											tabletemp->ffield[k].key[n].intkey = tableroot->next->pos->ffield[m].key[j].intkey;
											tabletemp->ffield[k].type = 0;
										}
										if (tableroot->next->pos->ffield[m].type == 1)
										{
											tabletemp->ffield[k].key[n].dkey = tableroot->next->pos->ffield[m].key[j].dkey;
											tabletemp->ffield[k].type = 1;
										}
										else
										{
											strcpy(tabletemp->ffield[k].key[n].skey, tableroot->next->pos->ffield[m].key[j].skey);
											tabletemp->ffield[k].type = 2;
										}
										k++;
									}
									n++;
								}
							}
						}
						tabletemp->ilen = n; // 数据总量达到n=item1*item2
					}
					fn = tabletemp->flen;
					if (pTmpNode != tableroot)
					{
						freeTable(pTmpNode->pos); // 释放当前大表
						struct table_def *tp = tableroot;
						tableroot = tableroot->next;
						free(tp);
						tp = NULL;
					}
					else
					{
						struct table_def *tp = tableroot;
						tableroot = tableroot->next;
						free(tp);
						tp = NULL;
					}
					pTmpNode->pos = tabletemp; // 获取新的大表
											   // printtable(pTmpNode->pos);
				}
			}
			itemtemp = itemroot; // 需要保留的字段
			while (itemtemp != NULL)
			{
				for (i = 0; i < tabletemp->flen; i++) // 遍历大表的字段
				{
					if (strcmp(itemtemp->field, tabletemp->ffield[i].name) == 0)
					{
						itemtemp->pos = &tabletemp->ffield[i]; // 相等就填
						break;
					}
				}
				if (i == tabletemp->flen)
				{
					printf("error: Column name does not match the table definition!\n...\nSQL>");
					freeCons(conroot);
					freeItems(itemroot);
					freeTables(tableroot);
					return;
				}
				itemtemp = itemtemp->next;
			}
			if (itemroot == NULL) // 全部打印
			{
				for (j = 0; j < tabletemp->flen; j++)
				{
					printf("%-20s  ", tabletemp->ffield[j].name);
				}
				printf("\n");
			}
			else // 按大表打印
			{
				itemtemp = itemroot;
				while (itemtemp != NULL)
				{
					printf("%-20s  ", itemtemp->field);
					itemtemp = itemtemp->next;
				}
				printf("\n");
			}
			for (i = 0; i < tabletemp->ilen; i++) // 按where筛选
			{
				if (whereTF(i, tabletemp, conroot) == TRUE)
				{
					if (itemroot == NULL)
					{
						for (j = 0; j < tabletemp->flen; j++)
						{
							if (tabletemp->ffield[j].type == 0)
								printf("%-20d  ", tabletemp->ffield[j].key[i].intkey);
							else if (tabletemp->ffield[j].type == 1)
								printf("%-20f  ", tabletemp->ffield[j].key[i].dkey);
							else
								printf("%-20s  ", tabletemp->ffield[j].key[i].skey);
						}
						printf("\n");
					}
					else
					{
						itemtemp = itemroot;
						while (itemtemp != NULL)
						{
							if (itemtemp->pos->type == 0)
								printf("%-20d  ", itemtemp->pos->key[i].intkey);
							if (itemtemp->pos->type == 1)
								printf("%-20f  ", itemtemp->pos->key[i].dkey);
							else
								printf("%-20s  ", itemtemp->pos->key[i].skey);
							itemtemp = itemtemp->next;
						}
						printf("\n");
					}
				}
			}
			freeCons(conroot);
			freeItems(itemroot);
			freeTables(tableroot);
			return;
		}
		dbtemp = dbtemp->next; // 找下一个数据库
	}
	freeCons(conroot);
	freeItems(itemroot);
	freeTables(tableroot);
	printf("error: Database %s doesn't exist!\n...\nSQL>", database);
}

/*删除操作。tableval为做删除的表的名称，conroot为条件二叉树的根节点，若为NULL，表示删除全部记录，
首先找到表，然后遍历表的每一条记录，若符合条件，则将后面的记录统一往前移动一条，将原纪录覆盖*/
void deletes(char *tableval, struct conditions_def *conroot)
{
	struct mydb *dbtemp = NULL;
	struct table *tabletemp = NULL;
	int i, j, k;
	if (dbroot != NULL)
		dbtemp = dbroot;
	else
	{
		printf("error: Please create a database first!\n...\nSQL>");
		freeCons(conroot);
		return;
	}
	while (dbtemp != NULL)
	{
		if (strcmp(dbtemp->name, database) == 0)
		{
			tabletemp = dbtemp->tbroot;
			while (tabletemp != NULL)
			{
				if (strcmp(tabletemp->name, tableval) == 0)
				{
					for (i = 0; i < tabletemp->ilen; i++)
					{
						if (whereTF(i, tabletemp, conroot) == TRUE)
						{
							for (k = i; k < tabletemp->ilen - 1; k++)
							{
								for (j = 0; j < tabletemp->flen; j++)
								{
									if (tabletemp->ffield[j].type == 0)
										tabletemp->ffield[j].key[k].intkey = tabletemp->ffield[j].key[k + 1].intkey;
									else if (tabletemp->ffield[j].type == 1)
										tabletemp->ffield[j].key[k].dkey = tabletemp->ffield[j].key[k + 1].dkey;
									else
										strcpy(tabletemp->ffield[j].key[k].skey, tabletemp->ffield[j].key[k + 1].skey);
								}
							}
							tabletemp->ilen--;
							i--;
						}
					}
					printf("Delete successfully!\n...\nSQL>");
					freeCons(conroot);
					return;
				}
				tabletemp = tabletemp->next;
			}
			printf("error: The table doesn't exist!\n...\nSQL>");
			freeCons(conroot);
			return;
		}
		dbtemp = dbtemp->next;
	}
	freeCons(conroot);
	printf("error: Database %s doesn not exist!\n...\nSQL>", database);
}

/*更新操作。tableval是要更新的表名称，uproot为赋值结构链表，conroot为条件二叉树的根节点。
先找到要更新的表，然后遍历赋值结构链表，找到对应的字段，并将其地址赋给每个赋值结构的pos变量，
便于后续操作，然后遍历表的每一条记录，判断符合条件则将对应的字段更新为对应的值*/
void updates(char *tableval, struct upcon_def *uproot, struct conditions_def *conroot)
{
	struct mydb *dbtemp = NULL;
	struct table *tabletemp = NULL;
	struct upcon_def *uptemp = NULL;
	int i, j;
	if (dbroot != NULL)
		dbtemp = dbroot;
	else
	{
		printf("error: Please create a database first!\n...\nSQL>");
		freeCons(conroot);
		freeUpcon(uproot);
		return;
	}
	while (dbtemp != NULL)
	{
		if (strcmp(dbtemp->name, database) == 0)
		{
			tabletemp = dbtemp->tbroot;
			while (tabletemp != NULL)
			{
				if (strcmp(tabletemp->name, tableval) == 0)
				{
					uptemp = uproot;
					while (uptemp != NULL)
					{
						for (i = 0; i < tabletemp->flen; i++)
						{
							if (strcmp(tabletemp->ffield[i].name, uptemp->field) == 0)
							{
								uptemp->pos = &tabletemp->ffield[i];
								break;
							}
						}
						if (i == tabletemp->flen)
						{
							printf("error: Field %s does not exist!\n...\nSQL>", uptemp->field);
							freeCons(conroot);
							freeUpcon(uproot);
							return;
						}
						uptemp = uptemp->next;
					}
					for (i = 0; i < tabletemp->ilen; i++)
					{
						if (whereTF(i, tabletemp, conroot) == TRUE)
						{
							uptemp = uproot;
							while (uptemp != NULL)
							{
								if (uptemp->pos->type == 0 && uptemp->type == 0)
									uptemp->pos->key[i].intkey = uptemp->value.intkey;
								else if (uptemp->pos->type == 1 && uptemp->type == 1)
									uptemp->pos->key[i].dkey = uptemp->value.dkey;
								else if (uptemp->pos->type == 2 && uptemp->type == 2)
									strcpy(uptemp->pos->key[i].skey, uptemp->value.skey);
								else
								{
									printf("error: Data type mismatch!\n...\nSQL>");
									freeCons(conroot);
									freeUpcon(uproot);
									return;
								}
								uptemp = uptemp->next;
							}
						}
					}
					printf("Update successfully!\n...\nSQL>");
					freeCons(conroot);
					freeUpcon(uproot);
					return;
				}
				tabletemp = tabletemp->next;
			}
			printf("error: The table doesn't exist!\n...\nSQL>");
			freeCons(conroot);
			freeUpcon(uproot);
			return;
		}
		dbtemp = dbtemp->next;
	}
	freeCons(conroot);
	printf("error: Database %s doesn not exist!\n...\nSQL>", database);
}

/*丢弃表，即链表的删除节点操作，删除时释放内存*/
void dropTable(char *tableval)
{
	struct mydb *dbtemp = NULL;
	struct table *tabletemp = NULL;
	struct table *tabletod = NULL;
	int i, j;
	if (dbroot != NULL)
		dbtemp = dbroot;
	else
	{
		printf("error: Please create a database first!\n...\nSQL>");
		return;
	}
	while (dbtemp != NULL)
	{
		if (strcmp(dbtemp->name, database) == 0)
		{
			tabletemp = dbtemp->tbroot;
			if (strcmp(dbtemp->tbroot->name, tableval) == 0)
			{
				tabletod = dbtemp->tbroot;
				dbtemp->tbroot = dbtemp->tbroot->next;
				free(tabletod->ffield);
				free(tabletod);
				printf("Drop table successfully!\n...\nSQL>");
				return;
			}
			if (dbtemp->tbroot->next == NULL)
				dbtemp->tbroot = NULL;
			while (tabletemp->next != NULL)
			{
				if (strcmp(tabletemp->next->name, tableval) == 0)
				{
					tabletod = tabletemp->next;
					tabletemp->next = tabletemp->next->next;
					free(tabletod->ffield);
					free(tabletod);
					printf("Drop table successfully!\n...\nSQL>");
					return;
				}
				tabletemp = tabletemp->next;
			}
			if (strcmp(tabletemp->name, tableval) == 0)
			{
				free(tabletemp->ffield);
				free(tabletemp);
				printf("Drop table successfully!\n...\nSQL>");
				return;
			}
			printf("error: The table doesn't exist!\n...\nSQL>");
			return;
		}
		dbtemp = dbtemp->next;
	}
	printf("error: Database %s doesn not exist!\n...\nSQL>", database);
}

/*丢弃数据库，即链表的删除节点操作，删除时释放内存*/
void dropDB(char *dbname)
{
	struct mydb *dbtemp = NULL;
	struct mydb *dbtod = NULL;
	struct table *tabletemp = NULL;
	struct table *tabletod = NULL;
	int i, j;
	if (dbroot != NULL)
		dbtemp = dbroot;
	else
	{
		printf("error: Please create a database first!\n...\nSQL>");
		return;
	}
	if (strcmp(dbroot->name, dbname) == 0)
	{
		tabletemp = dbroot->tbroot;
		while (tabletemp != NULL)
		{
			tabletod = tabletemp->next;
			free(tabletemp->ffield);
			free(tabletemp);
			tabletemp = tabletod;
		}
		dbtod = dbroot;
		dbroot = dbroot->next;
		free(dbtod);
		printf("Drop database successfully!\n...\nSQL>");
		return;
	}
	if (dbroot->next == NULL)
		dbroot = NULL;
	while (dbtemp->next != NULL)
	{
		if (strcmp(dbtemp->next->name, dbname) == 0)
		{
			tabletemp = dbtemp->next->tbroot;
			while (tabletemp != NULL)
			{
				tabletod = tabletemp->next;
				free(tabletemp->ffield);
				free(tabletemp);
				tabletemp = tabletod;
			}
			dbtod = dbtemp->next;
			dbtemp->next = dbtemp->next->next;
			free(dbtod);
			printf("Drop database successfully!\n...\nSQL>");
			return;
		}
		dbtemp = dbtemp->next;
	}
	if (strcmp(dbtemp->name, dbname) == 0)
	{
		tabletemp = dbtemp->tbroot;
		while (tabletemp != NULL)
		{
			tabletod = tabletemp->next;
			free(tabletemp->ffield);
			free(tabletemp);
			tabletemp = tabletod;
		}
		free(dbtemp);
		printf("Drop database successfully!\n...\nSQL>");
		return;
	}
	printf("error: Database %s doesn not exist!\n...\nSQL>", database);
}