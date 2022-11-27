#define _CRT_SECURE_NO_WARNINGS // scanf() ������ ����ϱ� ���� ��ó����
#include <stdio.h> // ���̺귯�� ���� ���� ��ó����
#define STUDENT 4 // ��ũ�� ��ó���� �ҽ��ڵ��� STUDENT�� ��� 4�� �ٲ۴�.

// �Լ� ����
void START(int x); 
void END();
void AVGPRINT(double x, double y, double z);


typedef struct Exam { // ����ü ���� <= �������� �����͸� �ϳ��� �ڷ���(struct Exam)���η� ���
	// ������ ������ �迭, ������ �迭�� �������� NULL���� �ڸ��� 
	char name[20]; 
	char num[10];
	int  kor, eng, mat, total;
	double avg;
}EXAM; // ����ü "struct Exam"�� �� �ٸ� �̸��� typedef�� => "EXAM"���� ���� ��

int main()
{
	EXAM STD[STUDENT], box; // ����ü ����, STUDENT�� 4�� ġȯ��
	int i, j, index;

	// ����(static) ���� ���� 
	// �� ���α׷��� ����ǵ� �� ����, ó�� ����� �� ���� �ʱ�ȭ, �ʱⰪ�� ������ �ڵ����� 0���� �ʱ�ȭ
	static double sumkor, sumeng, summat; 
	START(STUDENT); // ���α׷� ������ �˸��� �Լ� ȣ��
	for (i = 0; i < STUDENT; i++) {
		printf("%d�� ° �л��� �̸� : ", i + 1); 
		scanf("%s", &STD[i].name); // ����ü ������ ��� ���� �ÿ� ������.���
		printf("%d�� ° �л��� �й� : ", i + 1); 
		scanf("%s", &STD[i].num);
		printf("%d�� ° �л��� ���� ���� : ", i + 1); 
		scanf("%d", &STD[i].kor);
		printf("%d�� ° �л��� ���� ���� : ", i + 1); 
		scanf("%d", &STD[i].eng);
		printf("%d�� ° �л��� ���� ���� : ", i + 1);
		scanf("%d", &STD[i].mat);
		STD[i].total = STD[i].kor + STD[i].eng + STD[i].mat; // total�� i�� ������ ���� ����
		STD[i].avg = STD[i].total / 3.0; // avg�� ������ ��� ����
		
		// �л����� ���� ����� ���ϴµ� ���, 
		// sumkor, sumeng, summat�� ������ ������ ���� ����
		sumkor += STD[i].kor; 
		sumeng += STD[i].eng;
		summat += STD[i].mat;
	}

	// selection sort �߿�!
	for (i = 0; i < STUDENT-1; i++) { // STUDENT�� 4, �� 0, 1, 2 �� �ݺ�(�� ��ȣ�� �����ϸ� ���ϴ�)
		index = i; // �ϴ� ù ��° 0(�� ��ȣ)�� ���� ū ���̶� ����
		for (j = i + 1; j < STUDENT; j++) { // i�� ���ϱ� ���� j�� �ʱ갪�� ���ǽ��� i���� 1��ŭ ũ�� �Ͽ� �ݺ��ϰ� �� 1, 2, 3 �� �ݺ�
			if (STD[index].total < STD[j].total) index = j; // �񱳿����ڰ� <�� ��������, >�� ��������
		} // ù ��° 0�� 1, 2, 3�� ����� ���Ͽ� �� ū ���� �ε����� ����
		
		// ���� ū ���� ù ��° �ٿ� �����ϱ� ����
		box = STD[i]; // box������ STD[i]�� ��� ����
		STD[i] = STD[index]; // STD[i] ������ STD[index]�� ����
		STD[index] = box; // STD[index]�� box�� �����Ͽ� ��ġ�� �ٲ۴�!
	}
	END();
	for (i = 0; i < STUDENT; i++) {
		// -�� ������ ���� ����, ��� ������ ĭ ����, .�� ���ڴ� �Ҽ��� �ڸ� ǥ�� ĭ����
		printf("%-4d %-4s %-8s %-4d %-4d %-4d %-4d %-5.2f\n", i + 1, STD[i].name, STD[i].num, STD[i].kor, STD[i].eng, STD[i].mat, STD[i].total, STD[i].avg);
	}
	AVGPRINT(sumkor, sumeng, summat); // �Լ� ȣ��, ���� ���� ��� ���, ������ ���α׷��� ��ȯ
	return 0;
}


// ������ ���α׷��ֵ� �� 
void START(int x) // ���α׷� ���� �˸�
{
	printf("%d���� �л����� �̸��� ������ �Է¹޾� ���� ������ ����� ���Ͽ� ����� ���ϴ� ���α׷��Դϴ�.\n", x);
}
void END() // ��µǴ� �������� ������ �˷��ش�
{
	printf("��� �̸�   �й�      ���� ���� ���� ���� ���\n");
}
void AVGPRINT(double x, double y, double z) // ������ �л����� ��� ���� ���
{
	printf("���� ��� : %g\n���� ��� : %g\n���� ��� : %g\n", x/STUDENT, y/STUDENT, z/STUDENT);
}
