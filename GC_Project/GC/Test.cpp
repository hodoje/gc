////#include <stdio.h>
////#include "shared.h"
////#include "collector.h"
////
////typedef struct Struct_1
////{
////	int a;
////	int* b;
////} STRUCT_1;
////
////typedef struct Struct_2
////{
////	int c;
////	STRUCT_1* d;
////} STRUCT_2;
////
////typedef struct Struct_1_stressTest
////{
////	char* p;
////	long l1;
////	long l2;
////	long l3;
////	long l4;
////}SST1;
////
////typedef struct Struct_2_stressTest
////{
////	struct Struct_1_stressTest* p1;
////}SST2;
////
////typedef struct Struct_3_stressTest
////{
////	struct Struct_1_stressTest* p1;
////	struct Struct_1_stressTest* p2;
////	struct Struct_1_stressTest* p3;
////	struct Struct_2_stressTest* p4;
////	struct Struct_2_stressTest* p5;
////	struct Struct_2_stressTest* p6;
////}SST3;
////
////typedef struct Struct_4_stressTest
////{
////	struct Struct_1_stressTest* p1;
////	struct Struct_2_stressTest* p2;
////	struct Struct_3_stressTest* p3;
////}SST4;
////
////typedef struct Struct_5_stressTest
////{
////	struct Struct_1_stressTest* p1;
////	struct Struct_2_stressTest* p2;
////	struct Struct_3_stressTest* p3;
////	struct Struct_4_stressTest* p4;
////}SST5;
////
////typedef struct Struct_6_stressTest
////{
////	struct Struct_1_stressTest* p1;
////	struct Struct_2_stressTest* p2;
////	struct Struct_3_stressTest* p3;
////	struct Struct_4_stressTest* p4;
////	struct Struct_5_stressTest* p5;
////	struct Struct_6_stressTest* p6;
////	struct Struct_7_stressTest* p7;
////}SST6;
////
////typedef struct Struct_7_stressTest
////{
////	struct Struct_1_stressTest* p1;
////	struct Struct_2_stressTest* p2;
////	struct Struct_3_stressTest* p3;
////	struct Struct_4_stressTest* p4;
////	/*struct Struct_5_stressTest* p5;
////	struct Struct_6_stressTest* p6;
////	struct Struct_7_stressTest* p7;*/
////	long l1;
////	long l2;
////	long l3;
////	long l4;
////}SST7;
////
////typedef struct Struct_8_stressTest
////{
////	long l1;
////	long l2;
////	long l3;
////	long l4;
////	struct Struct_8_stressTest* p1;
////}SST8;
////
////typedef struct Struct_9_stressTest
////{
////	struct Struct_1_stressTest* p1;
////	struct Struct_2_stressTest* p2;
////	struct Struct_3_stressTest* p3;
////	struct Struct_4_stressTest* p4;
////	struct Struct_5_stressTest* p5;
////	struct Struct_6_stressTest* p6;
////	struct Struct_7_stressTest* p7;
////	struct Struct_8_stressTest* p8;
////	struct Struct_9_stressTest* p9;
////};
////
////
////int main()
////{
////	H_MANAGER* hM = HeapManagerInit();
////	char* a = (char*)Malloc(&hM, sizeof(char) * 1);
////	char* b = (char*)Malloc(&hM, sizeof(char) * 2);
////	char* c = (char*)Malloc(&hM, sizeof(char) * 4);
////	char* d = (char*)Malloc(&hM, sizeof(int) * 5);
////
////	//STRUCT_2* d = (STRUCT_2*)Malloc(&hM, sizeof(STRUCT_2));
////	//d->c = 5;
////	//d->d = (STRUCT_1*)Malloc(&hM, sizeof(STRUCT_1));
////	//d->d.b = (int*)Malloc(&hM, sizeof(int));
////	//int p = 5;
////	//d->d.b = &p;
////
////
////
////
////	//hM->free(&hM, &(void*)c);
////	char* e = (char*)Malloc(&hM, sizeof(char) * 5);
////	COLLECTOR* col = CollectorInit();
////
////	//for (int i = 0; i < 4; i++)
////	//{
////	//d[i] = 'A' + i;
////	//}
////
////	/*for (int i = 0; i < 5; i++)
////	{
////	printf("%d", a[i]);
////	}*/
////
////	for (int i = 0; i < 6; i++)
////	{
////		c[i] = 'A' + i + 5;
////	}
////
////	/*for (int i = 0; i < 4; i++)
////	{
////	printf("%d", b[i]);
////	}*/
////
////	//for (int i = 0; i < 2; i++)
////	//{
////	//	d[i] = 'A' + i * 2;
////	//}
////
////	for (int i = 0; i < 2; i++)
////	{
////		e[i] = 'A' + i * 3;
////	}
////
////	//// Stress-Test
////
////	//// Test case: not enough memmory on heap
////	//char* overload = (char*)Malloc(&hM, 3000);
////
////	//// Test case: 1000 structures with char* pointers
////	//SST1* array[100];
////
////	//for (int i = 0; i <= 100; i++)
////	//{
////	//	array[i] = (SST1*)Malloc(&hM, sizeof(SST1));
////	//	array[i]->p = (char*)Malloc(&hM, sizeof(char));
////	//}
////
////	// Test case: deep ptrs
////	SST7* s17 = (SST7*)Malloc(&hM, sizeof(SST7));
////	s17->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s17->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s17->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s17->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
////	s17->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p3->p4 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s17->p3->p5 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s17->p3->p6 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s17->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s17->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
////	s17->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
////	s17->p3->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p3->p5->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p3->p6->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p4 = (SST4*)Malloc(&hM, sizeof(SST4));
////	s17->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p4->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s17->p4->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
////	s17->p4->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s17->p4->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p4->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s17->p4->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p4->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s17->p4->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p4->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
////	s17->p4->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s17->p4->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
////
////	SST7* s27 = (SST7*)Malloc(&hM, sizeof(SST7));
////	s27->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s27->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s27->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s27->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
////	s27->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p3->p4 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s27->p3->p5 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s27->p3->p6 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s27->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s27->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
////	s27->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
////	s27->p3->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p3->p5->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p3->p6->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p4 = (SST4*)Malloc(&hM, sizeof(SST4));
////	s27->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p4->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s27->p4->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
////	s27->p4->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s27->p4->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p4->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s27->p4->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p4->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s27->p4->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p4->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
////	s27->p4->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s27->p4->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
////
////	SST7* s37 = (SST7*)Malloc(&hM, sizeof(SST7));
////	s37->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s37->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s37->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s37->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
////	s37->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p3->p4 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s37->p3->p5 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s37->p3->p6 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s37->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s37->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
////	s37->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
////	s37->p3->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p3->p5->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p3->p6->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p4 = (SST4*)Malloc(&hM, sizeof(SST4));
////	s37->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p4->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s37->p4->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
////	s37->p4->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s37->p4->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p4->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s37->p4->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p4->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s37->p4->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p4->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
////	s37->p4->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s37->p4->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
////
////	SST7* s47 = (SST7*)Malloc(&hM, sizeof(SST7));
////	s47->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s47->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s47->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s47->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
////	s47->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p3->p4 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s47->p3->p5 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s47->p3->p6 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s47->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s47->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
////	s47->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
////	s47->p3->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p3->p5->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p3->p6->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p4 = (SST4*)Malloc(&hM, sizeof(SST4));
////	s47->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p4->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s47->p4->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
////	s47->p4->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s47->p4->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p4->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s47->p4->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p4->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s47->p4->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p4->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
////	s47->p4->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s47->p4->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
////
////	SST7* s57 = (SST7*)Malloc(&hM, sizeof(SST7));
////	s57->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s57->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s57->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s57->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
////	s57->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p3->p4 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s57->p3->p5 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s57->p3->p6 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s57->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s57->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
////	s57->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
////	s57->p3->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p3->p5->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p3->p6->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p4 = (SST4*)Malloc(&hM, sizeof(SST4));
////	s57->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p4->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
////	s57->p4->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
////	s57->p4->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s57->p4->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p4->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s57->p4->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p4->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
////	s57->p4->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p4->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
////	s57->p4->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
////	s57->p4->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
////
////	col->rootSet[0] = (char*)s27;
////	col->rootSet[1] = (char*)s37;
////	col->rootSet[2] = (char*)s47;
////	col->rootSet[3] = (char*)s57;
////	col->MarkAndSweep(&hM, &col);
////
////	getchar();
////
////	return 0;
////}
//
////#include <stdio.h>
////#include "shared.h"
////#include "collector.h"
////
////int main()
////{
////	H_MANAGER* hM = HeapManagerInit();
////	//char* a = (char*)Malloc(&hM, sizeof(char) * 3);
////	//char* b = (char*)Malloc(&hM, sizeof(char) * 2);
////	//char* c = (char*)Malloc(&hM, sizeof(char) * 2);
////	//char* d = (char*)Malloc(&hM, sizeof(char) * 5);
////	//hM->free(&hM, &(void*)b);
////	//hM->free(&hM, &(void*)c);
////	//char* e = (char*)Malloc(&hM, sizeof(char) * 4);
////	COLLECTOR* col = CollectorInit();
////	GetRootCollection(&col, &hM);
////
////	return 0;
////}
//
//
//#include <stdio.h>
//#include "shared.h"
//#include "collector.h"
//#include <time.h>
//
//typedef struct Struct_1
//{
//	int a;
//	int* b;
//} STRUCT_1;
//
//typedef struct Struct_2
//{
//	int c;
//	STRUCT_1* d;
//} STRUCT_2;
//
//typedef struct Struct_1_stressTest
//{
//	char* p;
//	long l1;
//	long l2;
//	long l3;
//	long l4;
//}SST1;
//
//typedef struct Struct_2_stressTest
//{
//	struct Struct_1_stressTest* p1;
//}SST2;
//
//typedef struct Struct_3_stressTest
//{
//	struct Struct_1_stressTest* p1;
//	struct Struct_1_stressTest* p2;
//	struct Struct_1_stressTest* p3;
//	struct Struct_2_stressTest* p4;
//	struct Struct_2_stressTest* p5;
//	struct Struct_2_stressTest* p6;
//}SST3;
//
//typedef struct Struct_4_stressTest
//{
//	struct Struct_1_stressTest* p1;
//	struct Struct_2_stressTest* p2;
//	struct Struct_3_stressTest* p3;
//}SST4;
//
//typedef struct Struct_5_stressTest
//{
//	struct Struct_1_stressTest* p1;
//	struct Struct_2_stressTest* p2;
//	struct Struct_3_stressTest* p3;
//	struct Struct_4_stressTest* p4;
//}SST5;
//
//typedef struct Struct_6_stressTest
//{
//	struct Struct_1_stressTest* p1;
//	struct Struct_2_stressTest* p2;
//	struct Struct_3_stressTest* p3;
//	struct Struct_4_stressTest* p4;
//	struct Struct_5_stressTest* p5;
//	struct Struct_6_stressTest* p6;
//	struct Struct_7_stressTest* p7;
//}SST6;
//
//typedef struct Struct_7_stressTest
//{
//	struct Struct_1_stressTest* p1;
//	struct Struct_2_stressTest* p2;
//	struct Struct_3_stressTest* p3;
//	struct Struct_4_stressTest* p4;
//	/*struct Struct_5_stressTest* p5;
//	struct Struct_6_stressTest* p6;
//	struct Struct_7_stressTest* p7;*/
//	long l1;
//	long l2;
//	long l3;
//	long l4;
//}SST7;
//
//typedef struct Struct_8_stressTest
//{
//	long l1;
//	long l2;
//	long l3;
//	long l4;
//	struct Struct_8_stressTest* p1;
//}SST8;
//
//typedef struct Struct_9_stressTest
//{
//	struct Struct_1_stressTest* p1;
//	struct Struct_2_stressTest* p2;
//	struct Struct_3_stressTest* p3;
//	struct Struct_4_stressTest* p4;
//	struct Struct_5_stressTest* p5;
//	struct Struct_6_stressTest* p6;
//	struct Struct_7_stressTest* p7;
//	struct Struct_8_stressTest* p8;
//	struct Struct_9_stressTest* p9;
//};
////
////
//int main()
//{
//	H_MANAGER* hM = HeapManagerInit();
//	//	char* a = (char*)Malloc(&hM, sizeof(char) * 1);
//	//	char* b = (char*)Malloc(&hM, sizeof(char) * 2);
//	//	char* c = (char*)Malloc(&hM, sizeof(char) * 4);
//	//	char* d = (char*)Malloc(&hM, sizeof(int) * 5);
//	//
//	//	//STRUCT_2* d = (STRUCT_2*)Malloc(&hM, sizeof(STRUCT_2));
//	//	//d->c = 5;
//	//	//d->d = (STRUCT_1*)Malloc(&hM, sizeof(STRUCT_1));
//	//	//d->d.b = (int*)Malloc(&hM, sizeof(int));
//	//	//int p = 5;
//	//	//d->d.b = &p;
//	//
//	//
//	//
//	//
//	//	//hM->free(&hM, &(void*)c);
//	//	char* e = (char*)Malloc(&hM, sizeof(char) * 5);
//	COLLECTOR* col = CollectorInit();
//	//
//	//	//for (int i = 0; i < 4; i++)
//	//	//{
//	//	//d[i] = 'A' + i;
//	//	//}
//	//
//	//	/*for (int i = 0; i < 5; i++)
//	//	{
//	//	printf("%d", a[i]);
//	//	}*/
//	//
//	//	for (int i = 0; i < 6; i++)
//	//	{
//	//		c[i] = 'A' + i + 5;
//	//	}
//	//
//	//	/*for (int i = 0; i < 4; i++)
//	//	{
//	//	printf("%d", b[i]);
//	//	}*/
//	//
//	//	//for (int i = 0; i < 2; i++)
//	//	//{
//	//	//	d[i] = 'A' + i * 2;
//	//	//}
//	//
//	//	for (int i = 0; i < 2; i++)
//	//	{
//	//		e[i] = 'A' + i * 3;
//	//	}
//	//
//	//	//// Stress-Test
//	//
//	//	//// Test case: not enough memmory on heap
//	//	//char* overload = (char*)Malloc(&hM, 3000);
//	//
//	//	//// Test case: 1000 structures with char* pointers
//	//	//SST1* array[100];
//	//
//	//	//for (int i = 0; i <= 100; i++)
//	//	//{
//	//	//	array[i] = (SST1*)Malloc(&hM, sizeof(SST1));
//	//	//	array[i]->p = (char*)Malloc(&hM, sizeof(char));
//	//	//}
//	//
//	// Test case: deep ptrs
//	SST7* array[100];
//
//	clock_t start = clock();
//	for (int i = 0; i < 100; i++)
//	{
//		SST7* s17 = (SST7*)Malloc(&hM, sizeof(SST7));
//		s17->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p1->p = (char*)Malloc(&hM, sizeof(char));
//		s17->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
//		s17->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
//		s17->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
//		s17->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p3->p4 = (SST2*)Malloc(&hM, sizeof(SST2));
//		s17->p3->p5 = (SST2*)Malloc(&hM, sizeof(SST2));
//		s17->p3->p6 = (SST2*)Malloc(&hM, sizeof(SST2));
//		s17->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
//		s17->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
//		s17->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
//		s17->p3->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p3->p5->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p3->p6->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p4 = (SST4*)Malloc(&hM, sizeof(SST4));
//		s17->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p4->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
//		s17->p4->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
//		s17->p4->p1->p = (char*)Malloc(&hM, sizeof(char));
//		s17->p4->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p4->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
//		s17->p4->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p4->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
//		s17->p4->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p4->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
//		s17->p4->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
//		s17->p4->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
//
//		array[i] = s17;
//	}
//
//	clock_t end = clock();
//    float seconds = (float)(end - start) / CLOCKS_PER_SEC;
//
//	//char* bigData = (char*)Malloc(&hM, sizeof(char) * 100000000);
//
//	col->rootSet[0] = (char*)array[0];
//	col->rootSet[1] = (char*)array[670];
//	col->rootSet[2] = (char*)array[320];
//	col->rootSet[3] = (char*)array[900];
//	start = clock();
//	col->MarkAndSweep(&hM, &col);
//	end = clock();
//	seconds = (float)(end - start) / CLOCKS_PER_SEC;
//	getchar();
//
//	return 0;
//}
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
////#include <stdio.h>
////#include "shared.h"
////#include "collector.h"
////#include <time.h>
////
//////typedef struct Struct_1
//////{
//////	int a;
//////	int* b;
//////} STRUCT_1;
//////
//////typedef struct Struct_2
//////{
//////	int c;
//////	STRUCT_1* ddd;
//////} STRUCT_2;
////
////typedef struct STR
////{
////	int a;
////	int b;
////	int c;
////	int d;
////	int e;
////	int f;
////	int g;
////	int h;
////	int i;
////	int j;
////} STR;
////
////typedef struct STR2
////{
////	STR* aa;
////	STR* bb;
////	STR* cc;
////	STR* dd;
////	STR* ee;
////	STR* ff;
////	STR* gg;
////	STR* hh;
////	STR* ii;
////	STR* jj;
////} STR2;
////
////typedef struct STR3 {
////	STR2* aaa;
////	STR2* bbb;
////	STR2* ccc;
////} STR3;
////
////DWORD WINAPI f(LPVOID lpParam)
////{
////	printf("Funkcija iz threada.\n");
////	printf("%d", *((int*)lpParam));
////
////	return 0;
////}
////
////int main()
////{
////	H_MANAGER* hM = HeapManagerInit();
////	COLLECTOR* col = CollectorInit();
////	int broj = 5;
////	DWORD fId;
////	CreateThreadWrapper(&col, NULL, 0, &f, (void*)&broj, 0, &fId);
////	/*clock_t start = clock();
////	STR3* a = (STR3*)malloc(sizeof(STR3));
////	a->aaa = (STR2*)malloc(sizeof(STR2));
////	a->bbb = (STR2*)malloc(sizeof(STR2));
////	a->ccc = (STR2*)malloc(sizeof(STR2));
////	a->aaa->aa = (STR*)malloc(sizeof(STR));
////	a->aaa->bb = (STR*)malloc(sizeof(STR));
////	a->aaa->cc = (STR*)malloc(sizeof(STR));
////	a->aaa->dd = (STR*)malloc(sizeof(STR));
////	a->aaa->ee = (STR*)malloc(sizeof(STR));
////	a->aaa->ff = (STR*)malloc(sizeof(STR));
////	a->aaa->gg = (STR*)malloc(sizeof(STR));
////	a->aaa->hh = (STR*)malloc(sizeof(STR));
////	a->aaa->ii = (STR*)malloc(sizeof(STR));
////	a->aaa->jj = (STR*)malloc(sizeof(STR));
////	a->bbb->aa = (STR*)malloc(sizeof(STR));
////	a->bbb->bb = (STR*)malloc(sizeof(STR));
////	a->bbb->cc = (STR*)malloc(sizeof(STR));
////	a->bbb->dd = (STR*)malloc(sizeof(STR));
////	a->bbb->ee = (STR*)malloc(sizeof(STR));
////	a->bbb->ff = (STR*)malloc(sizeof(STR));
////	a->bbb->gg = (STR*)malloc(sizeof(STR));
////	a->bbb->hh = (STR*)malloc(sizeof(STR));
////	a->bbb->ii = (STR*)malloc(sizeof(STR));
////	a->bbb->jj = (STR*)malloc(sizeof(STR));
////	a->ccc->aa = (STR*)malloc(sizeof(STR));
////	a->ccc->bb = (STR*)malloc(sizeof(STR));
////	a->ccc->cc = (STR*)malloc(sizeof(STR));
////	a->ccc->dd = (STR*)malloc(sizeof(STR));
////	a->ccc->ee = (STR*)malloc(sizeof(STR));
////	a->ccc->ff = (STR*)malloc(sizeof(STR));
////	a->ccc->gg = (STR*)malloc(sizeof(STR));
////	a->ccc->hh = (STR*)malloc(sizeof(STR));
////	a->ccc->ii = (STR*)malloc(sizeof(STR));
////	a->ccc->jj = (STR*)malloc(sizeof(STR));
////
////	STR3* b = (STR3*)malloc(sizeof(STR3));
////	b->aaa = (STR2*)malloc(sizeof(STR2));
////	b->bbb = (STR2*)malloc(sizeof(STR2));
////	b->ccc = (STR2*)malloc(sizeof(STR2));
////	b->aaa->aa = (STR*)malloc(sizeof(STR));
////	b->aaa->bb = (STR*)malloc(sizeof(STR));
////	b->aaa->cc = (STR*)malloc(sizeof(STR));
////	b->aaa->dd = (STR*)malloc(sizeof(STR));
////	b->aaa->ee = (STR*)malloc(sizeof(STR));
////	b->aaa->ff = (STR*)malloc(sizeof(STR));
////	b->aaa->gg = (STR*)malloc(sizeof(STR));
////	b->aaa->hh = (STR*)malloc(sizeof(STR));
////	b->aaa->ii = (STR*)malloc(sizeof(STR));
////	b->aaa->jj = (STR*)malloc(sizeof(STR));
////	b->bbb->aa = (STR*)malloc(sizeof(STR));
////	b->bbb->bb = (STR*)malloc(sizeof(STR));
////	b->bbb->cc = (STR*)malloc(sizeof(STR));
////	b->bbb->dd = (STR*)malloc(sizeof(STR));
////	b->bbb->ee = (STR*)malloc(sizeof(STR));
////	b->bbb->ff = (STR*)malloc(sizeof(STR));
////	b->bbb->gg = (STR*)malloc(sizeof(STR));
////	b->bbb->hh = (STR*)malloc(sizeof(STR));
////	b->bbb->ii = (STR*)malloc(sizeof(STR));
////	b->bbb->jj = (STR*)malloc(sizeof(STR));
////	b->ccc->aa = (STR*)malloc(sizeof(STR));
////	b->ccc->bb = (STR*)malloc(sizeof(STR));
////	b->ccc->cc = (STR*)malloc(sizeof(STR));
////	b->ccc->dd = (STR*)malloc(sizeof(STR));
////	b->ccc->ee = (STR*)malloc(sizeof(STR));
////	b->ccc->ff = (STR*)malloc(sizeof(STR));
////	b->ccc->gg = (STR*)malloc(sizeof(STR));
////	b->ccc->hh = (STR*)malloc(sizeof(STR));
////	b->ccc->ii = (STR*)malloc(sizeof(STR));
////	b->ccc->jj = (STR*)malloc(sizeof(STR));
////
////	STR3* c = (STR3*)malloc(sizeof(STR3));
////	c->aaa = (STR2*)malloc(sizeof(STR2));
////	c->bbb = (STR2*)malloc(sizeof(STR2));
////	c->ccc = (STR2*)malloc(sizeof(STR2));
////	c->aaa->aa = (STR*)malloc(sizeof(STR));
////	c->aaa->bb = (STR*)malloc(sizeof(STR));
////	c->aaa->cc = (STR*)malloc(sizeof(STR));
////	c->aaa->dd = (STR*)malloc(sizeof(STR));
////	c->aaa->ee = (STR*)malloc(sizeof(STR));
////	c->aaa->ff = (STR*)malloc(sizeof(STR));
////	c->aaa->gg = (STR*)malloc(sizeof(STR));
////	c->aaa->hh = (STR*)malloc(sizeof(STR));
////	c->aaa->ii = (STR*)malloc(sizeof(STR));
////	c->aaa->jj = (STR*)malloc(sizeof(STR));
////	c->bbb->aa = (STR*)malloc(sizeof(STR));
////	c->bbb->bb = (STR*)malloc(sizeof(STR));
////	c->bbb->cc = (STR*)malloc(sizeof(STR));
////	c->bbb->dd = (STR*)malloc(sizeof(STR));
////	c->bbb->ee = (STR*)malloc(sizeof(STR));
////	c->bbb->ff = (STR*)malloc(sizeof(STR));
////	c->bbb->gg = (STR*)malloc(sizeof(STR));
////	c->bbb->hh = (STR*)malloc(sizeof(STR));
////	c->bbb->ii = (STR*)malloc(sizeof(STR));
////	c->bbb->jj = (STR*)malloc(sizeof(STR));
////	c->ccc->aa = (STR*)malloc(sizeof(STR));
////	c->ccc->bb = (STR*)malloc(sizeof(STR));
////	c->ccc->cc = (STR*)malloc(sizeof(STR));
////	c->ccc->dd = (STR*)malloc(sizeof(STR));
////	c->ccc->ee = (STR*)malloc(sizeof(STR));
////	c->ccc->ff = (STR*)malloc(sizeof(STR));
////	c->ccc->gg = (STR*)malloc(sizeof(STR));
////	c->ccc->hh = (STR*)malloc(sizeof(STR));
////	c->ccc->ii = (STR*)malloc(sizeof(STR));
////	c->ccc->jj = (STR*)malloc(sizeof(STR));
////
////	STR3* d = (STR3*)malloc(sizeof(STR3));
////	d->aaa = (STR2*)malloc(sizeof(STR2));
////	d->bbb = (STR2*)malloc(sizeof(STR2));
////	d->ccc = (STR2*)malloc(sizeof(STR2));
////	d->aaa->aa = (STR*)malloc(sizeof(STR));
////	d->aaa->bb = (STR*)malloc(sizeof(STR));
////	d->aaa->cc = (STR*)malloc(sizeof(STR));
////	d->aaa->dd = (STR*)malloc(sizeof(STR));
////	d->aaa->ee = (STR*)malloc(sizeof(STR));
////	d->aaa->ff = (STR*)malloc(sizeof(STR));
////	d->aaa->gg = (STR*)malloc(sizeof(STR));
////	d->aaa->hh = (STR*)malloc(sizeof(STR));
////	d->aaa->ii = (STR*)malloc(sizeof(STR));
////	d->aaa->jj = (STR*)malloc(sizeof(STR));
////	d->bbb->aa = (STR*)malloc(sizeof(STR));
////	d->bbb->bb = (STR*)malloc(sizeof(STR));
////	d->bbb->cc = (STR*)malloc(sizeof(STR));
////	d->bbb->dd = (STR*)malloc(sizeof(STR));
////	d->bbb->ee = (STR*)malloc(sizeof(STR));
////	d->bbb->ff = (STR*)malloc(sizeof(STR));
////	d->bbb->gg = (STR*)malloc(sizeof(STR));
////	d->bbb->hh = (STR*)malloc(sizeof(STR));
////	d->bbb->ii = (STR*)malloc(sizeof(STR));
////	d->bbb->jj = (STR*)malloc(sizeof(STR));
////	d->ccc->aa = (STR*)malloc(sizeof(STR));
////	d->ccc->bb = (STR*)malloc(sizeof(STR));
////	d->ccc->cc = (STR*)malloc(sizeof(STR));
////	d->ccc->dd = (STR*)malloc(sizeof(STR));
////	d->ccc->ee = (STR*)malloc(sizeof(STR));
////	d->ccc->ff = (STR*)malloc(sizeof(STR));
////	d->ccc->gg = (STR*)malloc(sizeof(STR));
////	d->ccc->hh = (STR*)malloc(sizeof(STR));
////	d->ccc->ii = (STR*)malloc(sizeof(STR));
////	d->ccc->jj = (STR*)malloc(sizeof(STR));
////
////	STR3* e = (STR3*)malloc(sizeof(STR3));
////	e->aaa = (STR2*)malloc(sizeof(STR2));
////	e->bbb = (STR2*)malloc(sizeof(STR2));
////	e->ccc = (STR2*)malloc(sizeof(STR2));
////	e->aaa->aa = (STR*)malloc(sizeof(STR));
////	e->aaa->bb = (STR*)malloc(sizeof(STR));
////	e->aaa->cc = (STR*)malloc(sizeof(STR));
////	e->aaa->dd = (STR*)malloc(sizeof(STR));
////	e->aaa->ee = (STR*)malloc(sizeof(STR));
////	e->aaa->ff = (STR*)malloc(sizeof(STR));
////	e->aaa->gg = (STR*)malloc(sizeof(STR));
////	e->aaa->hh = (STR*)malloc(sizeof(STR));
////	e->aaa->ii = (STR*)malloc(sizeof(STR));
////	e->aaa->jj = (STR*)malloc(sizeof(STR));
////	e->bbb->aa = (STR*)malloc(sizeof(STR));
////	e->bbb->bb = (STR*)malloc(sizeof(STR));
////	e->bbb->cc = (STR*)malloc(sizeof(STR));
////	e->bbb->dd = (STR*)malloc(sizeof(STR));
////	e->bbb->ee = (STR*)malloc(sizeof(STR));
////	e->bbb->ff = (STR*)malloc(sizeof(STR));
////	e->bbb->gg = (STR*)malloc(sizeof(STR));
////	e->bbb->hh = (STR*)malloc(sizeof(STR));
////	e->bbb->ii = (STR*)malloc(sizeof(STR));
////	e->bbb->jj = (STR*)malloc(sizeof(STR));
////	e->ccc->aa = (STR*)malloc(sizeof(STR));
////	e->ccc->bb = (STR*)malloc(sizeof(STR));
////	e->ccc->cc = (STR*)malloc(sizeof(STR));
////	e->ccc->dd = (STR*)malloc(sizeof(STR));
////	e->ccc->ee = (STR*)malloc(sizeof(STR));
////	e->ccc->ff = (STR*)malloc(sizeof(STR));
////	e->ccc->gg = (STR*)malloc(sizeof(STR));
////	e->ccc->hh = (STR*)malloc(sizeof(STR));
////	e->ccc->ii = (STR*)malloc(sizeof(STR));
////	e->ccc->jj = (STR*)malloc(sizeof(STR));
////	clock_t end = clock();
////	float seconds = (float)(end - start) / CLOCKS_PER_SEC;*/
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////
////	clock_t start = clock();
////	STR3* a = (STR3*)Malloc(&hM, sizeof(STR3));
////	a->aaa = (STR2*)Malloc(&hM, sizeof(STR2));
////	a->bbb = (STR2*)Malloc(&hM, sizeof(STR2));
////	a->ccc = (STR2*)Malloc(&hM, sizeof(STR2));
////	a->aaa->aa = (STR*)Malloc(&hM, sizeof(STR));
////	a->aaa->bb = (STR*)Malloc(&hM, sizeof(STR));
////	a->aaa->cc = (STR*)Malloc(&hM, sizeof(STR));
////	a->aaa->dd = (STR*)Malloc(&hM, sizeof(STR));
////	a->aaa->ee = (STR*)Malloc(&hM, sizeof(STR));
////	a->aaa->ff = (STR*)Malloc(&hM, sizeof(STR));
////	a->aaa->gg = (STR*)Malloc(&hM, sizeof(STR));
////	a->aaa->hh = (STR*)Malloc(&hM, sizeof(STR));
////	a->aaa->ii = (STR*)Malloc(&hM, sizeof(STR));
////	a->aaa->jj = (STR*)Malloc(&hM, sizeof(STR));
////	a->bbb->aa = (STR*)Malloc(&hM, sizeof(STR));
////	a->bbb->bb = (STR*)Malloc(&hM, sizeof(STR));
////	a->bbb->cc = (STR*)Malloc(&hM, sizeof(STR));
////	a->bbb->dd = (STR*)Malloc(&hM, sizeof(STR));
////	a->bbb->ee = (STR*)Malloc(&hM, sizeof(STR));
////	a->bbb->ff = (STR*)Malloc(&hM, sizeof(STR));
////	a->bbb->gg = (STR*)Malloc(&hM, sizeof(STR));
////	a->bbb->hh = (STR*)Malloc(&hM, sizeof(STR));
////	a->bbb->ii = (STR*)Malloc(&hM, sizeof(STR));
////	a->bbb->jj = (STR*)Malloc(&hM, sizeof(STR));
////	a->ccc->aa = (STR*)Malloc(&hM, sizeof(STR));
////	a->ccc->bb = (STR*)Malloc(&hM, sizeof(STR));
////	a->ccc->cc = (STR*)Malloc(&hM, sizeof(STR));
////	a->ccc->dd = (STR*)Malloc(&hM, sizeof(STR));
////	a->ccc->ee = (STR*)Malloc(&hM, sizeof(STR));
////	a->ccc->ff = (STR*)Malloc(&hM, sizeof(STR));
////	a->ccc->gg = (STR*)Malloc(&hM, sizeof(STR));
////	a->ccc->hh = (STR*)Malloc(&hM, sizeof(STR));
////	a->ccc->ii = (STR*)Malloc(&hM, sizeof(STR));
////	a->ccc->jj = (STR*)Malloc(&hM, sizeof(STR));
////
////	STR3* b = (STR3*)Malloc(&hM, sizeof(STR3));
////	b->aaa = (STR2*)Malloc(&hM, sizeof(STR2));
////	b->bbb = (STR2*)Malloc(&hM, sizeof(STR2));
////	b->ccc = (STR2*)Malloc(&hM, sizeof(STR2));
////	b->aaa->aa = (STR*)Malloc(&hM, sizeof(STR));
////	b->aaa->bb = (STR*)Malloc(&hM, sizeof(STR));
////	b->aaa->cc = (STR*)Malloc(&hM, sizeof(STR));
////	b->aaa->dd = (STR*)Malloc(&hM, sizeof(STR));
////	b->aaa->ee = (STR*)Malloc(&hM, sizeof(STR));
////	b->aaa->ff = (STR*)Malloc(&hM, sizeof(STR));
////	b->aaa->gg = (STR*)Malloc(&hM, sizeof(STR));
////	b->aaa->hh = (STR*)Malloc(&hM, sizeof(STR));
////	b->aaa->ii = (STR*)Malloc(&hM, sizeof(STR));
////	b->aaa->jj = (STR*)Malloc(&hM, sizeof(STR));
////	b->bbb->aa = (STR*)Malloc(&hM, sizeof(STR));
////	b->bbb->bb = (STR*)Malloc(&hM, sizeof(STR));
////	b->bbb->cc = (STR*)Malloc(&hM, sizeof(STR));
////	b->bbb->dd = (STR*)Malloc(&hM, sizeof(STR));
////	b->bbb->ee = (STR*)Malloc(&hM, sizeof(STR));
////	b->bbb->ff = (STR*)Malloc(&hM, sizeof(STR));
////	b->bbb->gg = (STR*)Malloc(&hM, sizeof(STR));
////	b->bbb->hh = (STR*)Malloc(&hM, sizeof(STR));
////	b->bbb->ii = (STR*)Malloc(&hM, sizeof(STR));
////	b->bbb->jj = (STR*)Malloc(&hM, sizeof(STR));
////	b->ccc->aa = (STR*)Malloc(&hM, sizeof(STR));
////	b->ccc->bb = (STR*)Malloc(&hM, sizeof(STR));
////	b->ccc->cc = (STR*)Malloc(&hM, sizeof(STR));
////	b->ccc->dd = (STR*)Malloc(&hM, sizeof(STR));
////	b->ccc->ee = (STR*)Malloc(&hM, sizeof(STR));
////	b->ccc->ff = (STR*)Malloc(&hM, sizeof(STR));
////	b->ccc->gg = (STR*)Malloc(&hM, sizeof(STR));
////	b->ccc->hh = (STR*)Malloc(&hM, sizeof(STR));
////	b->ccc->ii = (STR*)Malloc(&hM, sizeof(STR));
////	b->ccc->jj = (STR*)Malloc(&hM, sizeof(STR));
////
////	STR3* c = (STR3*)Malloc(&hM, sizeof(STR3));
////	c->aaa = (STR2*)Malloc(&hM, sizeof(STR2));
////	c->bbb = (STR2*)Malloc(&hM, sizeof(STR2));
////	c->ccc = (STR2*)Malloc(&hM, sizeof(STR2));
////	c->aaa->aa = (STR*)Malloc(&hM, sizeof(STR));
////	c->aaa->bb = (STR*)Malloc(&hM, sizeof(STR));
////	c->aaa->cc = (STR*)Malloc(&hM, sizeof(STR));
////	c->aaa->dd = (STR*)Malloc(&hM, sizeof(STR));
////	c->aaa->ee = (STR*)Malloc(&hM, sizeof(STR));
////	c->aaa->ff = (STR*)Malloc(&hM, sizeof(STR));
////	c->aaa->gg = (STR*)Malloc(&hM, sizeof(STR));
////	c->aaa->hh = (STR*)Malloc(&hM, sizeof(STR));
////	c->aaa->ii = (STR*)Malloc(&hM, sizeof(STR));
////	c->aaa->jj = (STR*)Malloc(&hM, sizeof(STR));
////	c->bbb->aa = (STR*)Malloc(&hM, sizeof(STR));
////	c->bbb->bb = (STR*)Malloc(&hM, sizeof(STR));
////	c->bbb->cc = (STR*)Malloc(&hM, sizeof(STR));
////	c->bbb->dd = (STR*)Malloc(&hM, sizeof(STR));
////	c->bbb->ee = (STR*)Malloc(&hM, sizeof(STR));
////	c->bbb->ff = (STR*)Malloc(&hM, sizeof(STR));
////	c->bbb->gg = (STR*)Malloc(&hM, sizeof(STR));
////	c->bbb->hh = (STR*)Malloc(&hM, sizeof(STR));
////	c->bbb->ii = (STR*)Malloc(&hM, sizeof(STR));
////	c->bbb->jj = (STR*)Malloc(&hM, sizeof(STR));
////	c->ccc->aa = (STR*)Malloc(&hM, sizeof(STR));
////	c->ccc->bb = (STR*)Malloc(&hM, sizeof(STR));
////	c->ccc->cc = (STR*)Malloc(&hM, sizeof(STR));
////	c->ccc->dd = (STR*)Malloc(&hM, sizeof(STR));
////	c->ccc->ee = (STR*)Malloc(&hM, sizeof(STR));
////	c->ccc->ff = (STR*)Malloc(&hM, sizeof(STR));
////	c->ccc->gg = (STR*)Malloc(&hM, sizeof(STR));
////	c->ccc->hh = (STR*)Malloc(&hM, sizeof(STR));
////	c->ccc->ii = (STR*)Malloc(&hM, sizeof(STR));
////	c->ccc->jj = (STR*)Malloc(&hM, sizeof(STR));
////
////	STR3* d = (STR3*)Malloc(&hM, sizeof(STR3));
////	d->aaa = (STR2*)Malloc(&hM, sizeof(STR2));
////	d->bbb = (STR2*)Malloc(&hM, sizeof(STR2));
////	d->ccc = (STR2*)Malloc(&hM, sizeof(STR2));
////	d->aaa->aa = (STR*)Malloc(&hM, sizeof(STR));
////	d->aaa->bb = (STR*)Malloc(&hM, sizeof(STR));
////	d->aaa->cc = (STR*)Malloc(&hM, sizeof(STR));
////	d->aaa->dd = (STR*)Malloc(&hM, sizeof(STR));
////	d->aaa->ee = (STR*)Malloc(&hM, sizeof(STR));
////	d->aaa->ff = (STR*)Malloc(&hM, sizeof(STR));
////	d->aaa->gg = (STR*)Malloc(&hM, sizeof(STR));
////	d->aaa->hh = (STR*)Malloc(&hM, sizeof(STR));
////	d->aaa->ii = (STR*)Malloc(&hM, sizeof(STR));
////	d->aaa->jj = (STR*)Malloc(&hM, sizeof(STR));
////	d->bbb->aa = (STR*)Malloc(&hM, sizeof(STR));
////	d->bbb->bb = (STR*)Malloc(&hM, sizeof(STR));
////	d->bbb->cc = (STR*)Malloc(&hM, sizeof(STR));
////	d->bbb->dd = (STR*)Malloc(&hM, sizeof(STR));
////	d->bbb->ee = (STR*)Malloc(&hM, sizeof(STR));
////	d->bbb->ff = (STR*)Malloc(&hM, sizeof(STR));
////	d->bbb->gg = (STR*)Malloc(&hM, sizeof(STR));
////	d->bbb->hh = (STR*)Malloc(&hM, sizeof(STR));
////	d->bbb->ii = (STR*)Malloc(&hM, sizeof(STR));
////	d->bbb->jj = (STR*)Malloc(&hM, sizeof(STR));
////	d->ccc->aa = (STR*)Malloc(&hM, sizeof(STR));
////	d->ccc->bb = (STR*)Malloc(&hM, sizeof(STR));
////	d->ccc->cc = (STR*)Malloc(&hM, sizeof(STR));
////	d->ccc->dd = (STR*)Malloc(&hM, sizeof(STR));
////	d->ccc->ee = (STR*)Malloc(&hM, sizeof(STR));
////	d->ccc->ff = (STR*)Malloc(&hM, sizeof(STR));
////	d->ccc->gg = (STR*)Malloc(&hM, sizeof(STR));
////	d->ccc->hh = (STR*)Malloc(&hM, sizeof(STR));
////	d->ccc->ii = (STR*)Malloc(&hM, sizeof(STR));
////	d->ccc->jj = (STR*)Malloc(&hM, sizeof(STR));
////
////	STR3* e = (STR3*)Malloc(&hM, sizeof(STR3));
////	e->aaa = (STR2*)Malloc(&hM, sizeof(STR2));
////	e->bbb = (STR2*)Malloc(&hM, sizeof(STR2));
////	e->ccc = (STR2*)Malloc(&hM, sizeof(STR2));
////	e->aaa->aa = (STR*)Malloc(&hM, sizeof(STR));
////	e->aaa->bb = (STR*)Malloc(&hM, sizeof(STR));
////	e->aaa->cc = (STR*)Malloc(&hM, sizeof(STR));
////	e->aaa->dd = (STR*)Malloc(&hM, sizeof(STR));
////	e->aaa->ee = (STR*)Malloc(&hM, sizeof(STR));
////	e->aaa->ff = (STR*)Malloc(&hM, sizeof(STR));
////	e->aaa->gg = (STR*)Malloc(&hM, sizeof(STR));
////	e->aaa->hh = (STR*)Malloc(&hM, sizeof(STR));
////	e->aaa->ii = (STR*)Malloc(&hM, sizeof(STR));
////	e->aaa->jj = (STR*)Malloc(&hM, sizeof(STR));
////	e->bbb->aa = (STR*)Malloc(&hM, sizeof(STR));
////	e->bbb->bb = (STR*)Malloc(&hM, sizeof(STR));
////	e->bbb->cc = (STR*)Malloc(&hM, sizeof(STR));
////	e->bbb->dd = (STR*)Malloc(&hM, sizeof(STR));
////	e->bbb->ee = (STR*)Malloc(&hM, sizeof(STR));
////	e->bbb->ff = (STR*)Malloc(&hM, sizeof(STR));
////	e->bbb->gg = (STR*)Malloc(&hM, sizeof(STR));
////	e->bbb->hh = (STR*)Malloc(&hM, sizeof(STR));
////	e->bbb->ii = (STR*)Malloc(&hM, sizeof(STR));
////	e->bbb->jj = (STR*)Malloc(&hM, sizeof(STR));
////	e->ccc->aa = (STR*)Malloc(&hM, sizeof(STR));
////	e->ccc->bb = (STR*)Malloc(&hM, sizeof(STR));
////	e->ccc->cc = (STR*)Malloc(&hM, sizeof(STR));
////	e->ccc->dd = (STR*)Malloc(&hM, sizeof(STR));
////	e->ccc->ee = (STR*)Malloc(&hM, sizeof(STR));
////	e->ccc->ff = (STR*)Malloc(&hM, sizeof(STR));
////	e->ccc->gg = (STR*)Malloc(&hM, sizeof(STR));
////	e->ccc->hh = (STR*)Malloc(&hM, sizeof(STR));
////	e->ccc->ii = (STR*)Malloc(&hM, sizeof(STR));
////	e->ccc->jj = (STR*)Malloc(&hM, sizeof(STR));
////	clock_t end = clock();
////	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
////
////	//H_MANAGER* hM = HeapManagerInit();
////	//char* a = (char*)Malloc(&hM, sizeof(char) * 1);
////	//char* b = (char*)Malloc(&hM, sizeof(char) * 2);
////	//char* c = (char*)Malloc(&hM, sizeof(char) * 4);
////
////	//STRUCT_2* d = (STRUCT_2*)Malloc(&hM, sizeof(STRUCT_2));
////	//d->c = 5;
////	//d->ddd = (STRUCT_1*)Malloc(&hM, sizeof(STRUCT_1));
////	//d->ddd->b = (int*)Malloc(&hM, sizeof(int));
////	//int p = 5;
////	//d->ddd->b = &p;
////	//d->c = 7;
////
////
////
////	////hM->free(&hM, &(void*)c);
////	//char* e = (char*)Malloc(&hM, sizeof(char) * 5);
////	//COLLECTOR* col = CollectorInit();
////	col->rootSet[0] = (char*)a;
////	col->rootSet[1] = (char*)b;
////	/*col->rootSet[2] = (char*)d;*/
////	col->rootSet[2] = (char*)c;
////	col->rootSet[3] = (char*)e;
////
////	clock_t sstart = clock();
////	col->MarkAndSweep(&hM, &col);
////	clock_t send = clock();
////	float sseconds = (float)(send - sstart) / CLOCKS_PER_SEC;
////
////	getchar();
////
////	return 0;
////}


#include <stdio.h>
#include "shared.h"
#include "collector.h"
#include <time.h>

typedef struct Struct_1
{
	int a;
	int* b;
} STRUCT_1;

typedef struct Struct_2
{
	int c;
	STRUCT_1* d;
} STRUCT_2;

typedef struct Struct_1_stressTest
{
	char* p;
	long l1;
	long l2;
	long l3;
	long l4;
}SST1;

typedef struct Struct_2_stressTest
{
	struct Struct_1_stressTest* p1;
}SST2;

typedef struct Struct_3_stressTest
{
	struct Struct_1_stressTest* p1;
	struct Struct_1_stressTest* p2;
	struct Struct_1_stressTest* p3;
	struct Struct_2_stressTest* p4;
	struct Struct_2_stressTest* p5;
	struct Struct_2_stressTest* p6;
}SST3;

typedef struct Struct_4_stressTest
{
	struct Struct_1_stressTest* p1;
	struct Struct_2_stressTest* p2;
	struct Struct_3_stressTest* p3;
}SST4;

typedef struct Struct_5_stressTest
{
	struct Struct_1_stressTest* p1;
	struct Struct_2_stressTest* p2;
	struct Struct_3_stressTest* p3;
	struct Struct_4_stressTest* p4;
}SST5;

typedef struct Struct_6_stressTest
{
	struct Struct_1_stressTest* p1;
	struct Struct_2_stressTest* p2;
	struct Struct_3_stressTest* p3;
	struct Struct_4_stressTest* p4;
	struct Struct_5_stressTest* p5;
	struct Struct_6_stressTest* p6;
	struct Struct_7_stressTest* p7;
}SST6;

typedef struct Struct_7_stressTest
{
	struct Struct_1_stressTest* p1;
	struct Struct_2_stressTest* p2;
	struct Struct_3_stressTest* p3;
	struct Struct_4_stressTest* p4;
	/*struct Struct_5_stressTest* p5;
	struct Struct_6_stressTest* p6;
	struct Struct_7_stressTest* p7;*/
	long l1;
	long l2;
	long l3;
	long l4;
}SST7;

typedef struct Struct_8_stressTest
{
	long l1;
	long l2;
	long l3;
	long l4;
	struct Struct_8_stressTest* p1;
}SST8;

typedef struct Struct_9_stressTest
{
	struct Struct_1_stressTest* p1;
	struct Struct_2_stressTest* p2;
	struct Struct_3_stressTest* p3;
	struct Struct_4_stressTest* p4;
	struct Struct_5_stressTest* p5;
	struct Struct_6_stressTest* p6;
	struct Struct_7_stressTest* p7;
	struct Struct_8_stressTest* p8;
	struct Struct_9_stressTest* p9;
} SST9;
DWORD WINAPI ThreadAllocation(LPVOID lpParam);
DWORD WINAPI ThreadAllocationLong(LPVOID lpParam);

HANDLE threadArray[10];

DWORD WINAPI f(LPVOID params)
{
	int broj = *((int*)params);
	printf("Test from wrapped function. %d\n", broj);
	return 50;
}

struct struktura
{
	int a;
	int b;
};

DWORD WINAPI f2(LPVOID params)
{
	int a = ((struct struktura*)params)->a;
	int b = ((struct struktura*)params)->b;
	printf("%d, %d", a, b);
	return 0;
}
//
//

void DeinitializeGC(struct Heap_manager** hManager, struct Collector** collector)
{
	H_MANAGER* hM = *hManager;
	COLLECTOR* col = *collector;
	// FREE ZA HM
	NODE* temp;
	NODE* head = hM->listOfFree;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		free(&temp->blockInfo);
	}
	free(hM->heapStart);
	ReleaseSemaphore(hM->mallocSemaphore, 0, 0);
	CloseHandle(hM->mallocSemaphore);
	for(int i = 0; i < hM->hashMapOfOccupied->size; i++)
	{
		HASHMAP_ENTRY* temp;
		HASHMAP_ENTRY* head = hM->hashMapOfOccupied->buckets[i];
		if(head == NULL)
		{
			free(hM->hashMapOfOccupied->buckets[i]);
		}
		else
		{
			while (head != NULL)
			{
				temp = head;
				HEAP_BLOCK* hb = temp->blockInfo;
				free(hb);
				head = head->next;
				free(temp);
			}
		}	
	}
	free(hM->hashMapOfOccupied->buckets);
	free(hM->hashMapOfOccupied);
	free(hM);

	// FREE ZA COL
	free(col->threadArr);
	free(col);
}

int main()
{
	H_MANAGER* hM = HeapManagerInit();
	COLLECTOR* col = CollectorInit();
//
	THREAD_FUNCTION_WRAPPER_PARAMETERS tfwp2;
	tfwp2.userRoutine = ThreadAllocation;
	tfwp2.routineParameters = hM;
	HANDLE tH2 = CreateThreadWrapper(&col, tfwp2, NULL, 0, 0, NULL);

	THREAD_FUNCTION_WRAPPER_PARAMETERS tfwp3;
	tfwp3.userRoutine = ThreadAllocationLong;
	tfwp3.routineParameters = hM;
	HANDLE tH3 = CreateThreadWrapper(&col, tfwp3, NULL, 0, 0, NULL);
	//int broj = 5;
	//THREAD_FUNCTION_WRAPPER_PARAMETERS tfwp;
	//tfwp.userRoutine = f;
	//tfwp.routineParameters = &broj;
	//HANDLE tH = CreateThreadWrapper(&col, tfwp, NULL, 0, 0, NULL);

	//struct struktura str;
	//str.a = 6;
	//str.b = 7;
	//THREAD_FUNCTION_WRAPPER_PARAMETERS tfwp1;
	//tfwp1.userRoutine = f2;
	//tfwp1.routineParameters = &str;
	//HANDLE tH1 = CreateThreadWrapper(&col, tfwp1, NULL, 0, 0, NULL);

	//CloseThreadHandleWrapper(&col, tH);
	//CloseThreadHandleWrapper(&col, tH1);
//	for (int i = 0; i < 10; i++)
//	{
//		if (i % 2)
//		{
//			threadArray[i] = CreateThreadWrapper(&col, 0, 0, &ThreadAllocation, (LPVOID)(hM), 0, NULL);
//		}
//		else
//		{
//			threadArray[i] = CreateThreadWrapper(&col, 0, 0, &ThreadAllocationLong, (LPVOID)(hM), 0, NULL);
//		}
//	}
//
//	//while (1)
//	//{
//
//	//}
//
//	//	char* a = (char*)Malloc(&hM, sizeof(char) * 1);
//	//	char* b = (char*)Malloc(&hM, sizeof(char) * 2);
//	//	char* c = (char*)Malloc(&hM, sizeof(char) * 4);
//	//	char* d = (char*)Malloc(&hM, sizeof(int) * 5);
//	//
//	//	//STRUCT_2* d = (STRUCT_2*)Malloc(&hM, sizeof(STRUCT_2));
//	//	//d->c = 5;
//	//	//d->d = (STRUCT_1*)Malloc(&hM, sizeof(STRUCT_1));
//	//	//d->d.b = (int*)Malloc(&hM, sizeof(int));
//	//	//int p = 5;
//	//	//d->d.b = &p;
//	//
//	//
//	//
//	//
//	//	//hM->free(&hM, &(void*)c);
//	//	char* e = (char*)Malloc(&hM, sizeof(char) * 5);
//
//	//
//	//	//for (int i = 0; i < 4; i++)
//	//	//{
//	//	//d[i] = 'A' + i;
//	//	//}
//	//
//	//	/*for (int i = 0; i < 5; i++)
//	//	{
//	//	printf("%d", a[i]);
//	//	}*/
//	//
//	//	for (int i = 0; i < 6; i++)
//	//	{
//	//		c[i] = 'A' + i + 5;
//	//	}
//	//
//	//	/*for (int i = 0; i < 4; i++)
//	//	{
//	//	printf("%d", b[i]);
//	//	}*/
//	//
//	//	//for (int i = 0; i < 2; i++)
//	//	//{
//	//	//	d[i] = 'A' + i * 2;
//	//	//}
//	//
//	//	for (int i = 0; i < 2; i++)
//	//	{
//	//		e[i] = 'A' + i * 3;
//	//	}
//	//
//	//	//// Stress-Test
//	//
//	//	//// Test case: not enough memmory on heap
//	//	//char* overload = (char*)Malloc(&hM, 3000);
//	//
//	//	//// Test case: 1000 structures with char* pointers
//	//	//SST1* array[100];
//	//
//	//	//for (int i = 0; i <= 100; i++)
//	//	//{
//	//	//	array[i] = (SST1*)Malloc(&hM, sizeof(SST1));
//	//	//	array[i]->p = (char*)Malloc(&hM, sizeof(char));
//	//	//}
//	//
//	// Test case: deep ptrs
//	/*SST7* array[100];
//
//	clock_t start = clock();
//	for (int i = 0; i < 100; i++)
//	{
//	SST7* s17 = (SST7*)Malloc(&hM, sizeof(SST7));
//	s17->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p1->p = (char*)Malloc(&hM, sizeof(char));
//	s17->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
//	s17->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
//	s17->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
//	s17->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p3->p4 = (SST2*)Malloc(&hM, sizeof(SST2));
//	s17->p3->p5 = (SST2*)Malloc(&hM, sizeof(SST2));
//	s17->p3->p6 = (SST2*)Malloc(&hM, sizeof(SST2));
//	s17->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
//	s17->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
//	s17->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
//	s17->p3->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p3->p5->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p3->p6->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p4 = (SST4*)Malloc(&hM, sizeof(SST4));
//	s17->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p4->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
//	s17->p4->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
//	s17->p4->p1->p = (char*)Malloc(&hM, sizeof(char));
//	s17->p4->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p4->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
//	s17->p4->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p4->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
//	s17->p4->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p4->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
//	s17->p4->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
//	s17->p4->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
//
//	array[i] = s17;
//	}
//
//	clock_t end = clock();
//	float seconds = (float)(end - start) / CLOCKS_PER_SEC;*/
//
//	//char* bigData = (char*)Malloc(&hM, sizeof(char) * 100000000);
//
//	/*col->rootSet[0] = (char*)array[0];
//	col->rootSet[1] = (char*)array[670];
//	col->rootSet[2] = (char*)array[320];
//	col->rootSet[3] = (char*)array[900];
//	start = clock();
//	col->MarkAndSweep(&hM, &col);
//	end = clock();
//	seconds = (float)(end - start) / CLOCKS_PER_SEC;
//	getchar();*/
//
//	getchar();
//
//	/*for (int i = 0; i < 1; i++)
//	{
//		CloseHandle(threadArray[i]);
//	}*/
//
	

Sleep(3000);
CloseHandle(tH2);
	CloseHandle(tH3);

	DeinitializeGC(&hM, &col);

	return 0;
}

DWORD WINAPI ThreadAllocation(LPVOID lpParam)
{
	SST7* array[10];
	H_MANAGER* hM = ((H_MANAGER*)lpParam);

	clock_t start = clock();
	for (int i = 0; i < 10; i++)
	{
		SST7* s17 = (SST7*)Malloc(&hM, sizeof(SST7));
		s17->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
		s17->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
		s17->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p3->p4 = (SST2*)Malloc(&hM, sizeof(SST2));
		s17->p3->p5 = (SST2*)Malloc(&hM, sizeof(SST2));
		s17->p3->p6 = (SST2*)Malloc(&hM, sizeof(SST2));
		s17->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
		s17->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
		s17->p3->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p3->p5->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p3->p6->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4 = (SST4*)Malloc(&hM, sizeof(SST4));
		s17->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
		s17->p4->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
		s17->p4->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p4->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p4->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p4->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
		s17->p4->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4->p3->p3->p = (char*)Malloc(&hM, sizeof(char));

		array[i] = s17;
	}

	return 0;
}

DWORD WINAPI ThreadAllocationLong(LPVOID lpParam)
{
	SST7* array[10];
	H_MANAGER* hM = ((H_MANAGER*)lpParam);

	clock_t start = clock();
	for (int i = 0; i < 10; i++)
	{
		SST7* s17 = (SST7*)Malloc(&hM, sizeof(SST7));
		s17->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
		s17->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
		s17->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p3->p4 = (SST2*)Malloc(&hM, sizeof(SST2));
		s17->p3->p5 = (SST2*)Malloc(&hM, sizeof(SST2));
		s17->p3->p6 = (SST2*)Malloc(&hM, sizeof(SST2));
		s17->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
		s17->p3->p3->p = (char*)Malloc(&hM, sizeof(char));
		s17->p3->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p3->p5->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p3->p6->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4 = (SST4*)Malloc(&hM, sizeof(SST4));
		s17->p4->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4->p2 = (SST2*)Malloc(&hM, sizeof(SST2));
		s17->p4->p3 = (SST3*)Malloc(&hM, sizeof(SST3));
		s17->p4->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p4->p2->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4->p2->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p4->p3->p1 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4->p3->p1->p = (char*)Malloc(&hM, sizeof(char));
		s17->p4->p3->p2 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4->p3->p2->p = (char*)Malloc(&hM, sizeof(char));
		s17->p4->p3->p3 = (SST1*)Malloc(&hM, sizeof(SST1));
		s17->p4->p3->p3->p = (char*)Malloc(&hM, sizeof(char));

		array[i] = s17;
	}

	//while (1) {

	//}

	return 0;
}