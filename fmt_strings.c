#include <stdio.h>
#include <string.h>
int main () {
	char string[10];
	int A = -73;
	unsigned int B = 31337;

	strcpy(string, "sample");

	//様々なフォーマット文字列
	printf("[A] 10進法:%d, 16進法:%x, 符号なし10進法:%u\n", A, A, A);
	printf("[B] 10進法:%d, 16進法:%x, 符号なし10進法:%u\n", B, B, B);
	printf("[Bのフィールド幅指定] 3: '%3u', 10: '%10u', '%08u'\n", B, B, B);
	printf("[文字列] %s アドレス %08x\n", string, string);

	//単項アドレス
	printf("変数Aのアドレス:%08x\n", &A);
}
