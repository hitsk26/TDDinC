#include "mymath.h"
/*
 *	�e���`
*/

#define PI 3.141592


double deg2rad(double degree){
	double radian = PI / 180.0 * degree;
	return radian;
}

double rad2deg(double radian){
	double degree = 180.0 / PI * radian;
	return degree;
}

float myabs(float value)
{
	float result=0;

	if (value>=0){
	result=value;
	}
	else {
	result = -value;
	}
	
	return result;
}


double mysin(double x)
{
double EPS = 1e-08; /* ���̒l�������菬�����Ȃ����烋�[�v�I�� */
double s = 0.0; /* ���߂� sin �l */
int k; /* ���� */
int n; /* �����i1, 3, 5, 7, ...�j */
int sign = 1; /* ���Z�����Z���̂��߂̕ϐ��B1�����Ƃɕ��������] */
double diff; /* ���̒l (x^n/n!)*sign */
int i; /* ���[�v�p�̕ϐ� */

k = 1;
for (; ;) {
n = 2 * k - 1;
diff = 1.0;
/* x^n / n! */
for (i = 1; i <= n; i++)
{
diff *= x / i;
}
if(diff < EPS) {
break;
}
/* + or - */
diff *= sign;
s += diff;
k++;
sign *= -1;
}
return s;
}

double mycos(double x)
{
	return mysin(PI / 2 - x);
}