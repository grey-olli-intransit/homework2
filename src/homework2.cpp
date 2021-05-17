// Homework 2 , 20210514
// Практическое задание
// Создать и инициализировать переменные пройденных типов данных
// Создать перечисление с возможными вариантами символов для игры в крестики-нолики
//Создать массив, способный содержать значения такого перечисления и инициализировать его.
//* Создать структуру данных «Поле для игры в крестики-нолики» и снабдить его всеми необходимыми свойствами
//** Создать объединение и структуру с битовыми флагами указывающими какого типа значение в данный момент содержится в объединении
#include <iostream>
int main() {
   bool logical = true;
   printf("boolean value is %d AKA %s\n",logical,logical?"true":"false");
   short int small_int = 2;
   printf("short integer value is %d\n",small_int);
   printf("short integer size is %ld",sizeof(short));
   int integer = 1;
   printf("integer value is %d\n",integer);
   float floating_point = 2.0;
   printf("float value is %f\n",floating_point);
   double double_precision_fp = 3.0;
   printf("double value is %lf\n",double_precision_fp);
   char character = 'A';
   printf("char value is '%c'\n",character);
   unsigned int u_integer = 2U;
   printf("unsigned int value is %d\n",u_integer);
   long int long_int = 4L;
   printf("long int value is %ld\n",long_int);
   long long int huge_int = 9LL;
   printf("long long int value is %lld\n",huge_int);
   unsigned long long int very_huge_int = 3ULL;
   printf("unsigned long long int value is %lld\n",very_huge_int);
   typedef struct {
     int field1:1;
     int field2:1;
   } bitfield;
   char arr[]="string";
   printf("array as string: %s\n", arr);
   constexpr int index = 3; // чтобы можно было использовать в индексе массива имя, оно так объявляется
                            // указыавая, что значение константы фиксируется и определяется во время сборки
   char arr1[index]="as";
   printf("another array as string: %s\n", arr1);
   int arr3[][2]={{2,3},{4,5}};
   for(int i=0;i<2;i++)
       for(int j=0;j<2;j++)
	  printf("arr3[%d][%d]: %d\n",i,j,arr3[i][j]);
   // c++11 variable, should be guessed as integer
   auto i_std11var=3;
   printf("auto variable value is %d\n", i_std11var);
   auto f_std11var=3.0;
   printf("auto variable value is %f\n", f_std11var);

   bitfield sample_bit_field_structure = {0};
   printf("Bit fields values: %d and %d\n", sample_bit_field_structure.field1,
		   sample_bit_field_structure.field2);

   enum KrestikiNoliki {Empty,Krestik, Nolik};
   KrestikiNoliki field[3][3]={Krestik,Empty,Empty,
                         Nolik,Nolik,Empty,
                         Empty,Empty,Nolik};
  for(int i=0;i<3;i++) {
      if (i==0) printf("  . A . B . C .  ");
      printf("\n...............\n%d ",i+1);
      for(int j=0;j<3;j++) {
          printf(".");
	  if (field[i][j] == Empty)
	     printf("   ");
	  else if (field[i][j] == Krestik)
	     printf(" X ");
	  else
             printf(" 0 ");
          if (j==2)
              printf(".");
      }
      if (i==2)
          printf("\n..............\n");
  }    
  
  struct KrestikiNolikiField {
    KrestikiNoliki field_array[3][3];
    int ojidanie_hoda; // это и нижеследующее можно и вне структуры задавать.
    int winner;
  };

  union sample_union {
   int thisflag:1;
   char justchar;
   float thefloat;
  };
  
  enum union_content {type_int, type_char, type_float,type_not_initialized};
  struct union_with_its_content_type {
    union_content what_in_union;
    sample_union su;
  };
  
  union_with_its_content_type uwict;
  uwict.what_in_union = type_int;
  uwict.su.thisflag=0b1;
  if (uwict.what_in_union == type_int) 
    printf("union contains int\n");
  else if (uwict.what_in_union == type_char)
    printf("union contains char\n");
  else if (uwict.what_in_union == type_float)
    printf("union contains float\n");
  else
    printf("union is not initialised.\n");
  return 0;
}
