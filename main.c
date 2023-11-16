#include "ft_printf.h"

int main()
{
	// int n = 687;// %xwtv)^G1%u'X#L5B%dWD8%XqER,J-t%cm'[%uCrK:8>JE%umDj@]t%%%X,%pW9ofcR\r", -1498232592, 803153719, -388817324, 30121709, 412441291, 1936789744, -1732028266, 853249075, (void *)8385425183114035570
	// const char *str = "asdasd asdasdasdASdas %hhas $SDASDasdasd";
	int i1 = ft_printf("%p", "");
	printf("\n");
	int i2 = printf("%p", "");
	printf("\nfake : %d\n", i1);
	printf("original : %d\n", i2);
}
/*
fake >> a6b2c8f0wtv)^G1803153719'X#L5B-388817324WD81CB9EEDqER,J-t�m'[1936789744CrK:8>JE2562939030mDj@]t%32DB8C33,0x745f03c6b2208172W9ofcR^M$
original >> a6b2c8f0wtv)^G1803153719'X#L5B-388817324WD81CB9EEDqER,J-t�m'[1936789744CrK:8>JE2562939030mDj@]t%32DB8C33,0x745f03c6b2208172W9ofcR^M$

*/
