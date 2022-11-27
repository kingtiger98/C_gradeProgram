#define _CRT_SECURE_NO_WARNINGS // scanf() 경고없이 사용하기 위한 전처리기
#include <stdio.h> // 라이브러리 파일 포함 전처리기
#define STUDENT 4 // 매크로 전처리기 소스코드의 STUDENT를 모두 4로 바꾼다.

// 함수 선언
void START(int x); 
void END();
void AVGPRINT(double x, double y, double z);


typedef struct Exam { // 구조체 선언 <= 여러형의 데이터를 하나의 자료형(struct Exam)으로로 취급
	// 문자형 일차원 배열, 문자형 배열의 마지막은 NULL문자 자리임 
	char name[20]; 
	char num[10];
	int  kor, eng, mat, total;
	double avg;
}EXAM; // 구조체 "struct Exam"의 또 다른 이름을 typedef로 => "EXAM"으로 만든 것

int main()
{
	EXAM STD[STUDENT], box; // 구조체 선언, STUDENT는 4로 치환됨
	int i, j, index;

	// 정적(static) 변수 선언 
	// ㄴ 프로그램이 종료되도 값 유지, 처음 실행시 한 번만 초기화, 초기값이 없으면 자동으로 0으로 초기화
	static double sumkor, sumeng, summat; 
	START(STUDENT); // 프로그램 시작을 알리는 함수 호출
	for (i = 0; i < STUDENT; i++) {
		printf("%d번 째 학생의 이름 : ", i + 1); 
		scanf("%s", &STD[i].name); // 구조체 변수의 멤버 참소 시엔 변수명.멤버
		printf("%d번 째 학생의 학번 : ", i + 1); 
		scanf("%s", &STD[i].num);
		printf("%d번 째 학생의 국어 점수 : ", i + 1); 
		scanf("%d", &STD[i].kor);
		printf("%d번 째 학생의 영어 점수 : ", i + 1); 
		scanf("%d", &STD[i].eng);
		printf("%d번 째 학생의 수학 점수 : ", i + 1);
		scanf("%d", &STD[i].mat);
		STD[i].total = STD[i].kor + STD[i].eng + STD[i].mat; // total에 i의 국영수 총점 저장
		STD[i].avg = STD[i].total / 3.0; // avg에 국영수 평균 저장
		
		// 학생들의 과목별 평균을 구하는데 사용, 
		// sumkor, sumeng, summat에 국영수 각각의 총점 저장
		sumkor += STD[i].kor; 
		sumeng += STD[i].eng;
		summat += STD[i].mat;
	}

	// selection sort 중요!
	for (i = 0; i < STUDENT-1; i++) { // STUDENT는 4, 즉 0, 1, 2 만 반복(방 번호라 생각하면 편하다)
		index = i; // 일단 첫 번째 0(방 번호)이 가장 큰 값이라 생각
		for (j = i + 1; j < STUDENT; j++) { // i와 비교하기 위해 j로 초깃값과 조건식을 i보다 1만큼 크게 하여 반복하게 함 1, 2, 3 만 반복
			if (STD[index].total < STD[j].total) index = j; // 비교연산자가 <면 내림차순, >면 오름차순
		} // 첫 번째 0과 1, 2, 3의 값들과 비교하여 더 큰 방을 인덱스에 저장
		
		// 가장 큰 값을 첫 번째 바에 저장하기 위해
		box = STD[i]; // box변수에 STD[i]를 잠시 저장
		STD[i] = STD[index]; // STD[i] 변수에 STD[index]를 저장
		STD[index] = box; // STD[index]에 box를 저장하여 위치를 바꾼다!
	}
	END();
	for (i = 0; i < STUDENT; i++) {
		// -가 붙으면 왼쪽 정렬, 출력 정수는 칸 지정, .뒤 숫자는 소숫점 자리 표현 칸지정
		printf("%-4d %-4s %-8s %-4d %-4d %-4d %-4d %-5.2f\n", i + 1, STD[i].name, STD[i].num, STD[i].kor, STD[i].eng, STD[i].mat, STD[i].total, STD[i].avg);
	}
	AVGPRINT(sumkor, sumeng, summat); // 함수 호출, 과목별 성적 평균 출력, 구조적 프로그래밍 일환
	return 0;
}


// 구조적 프로그래밍들 ㄱ 
void START(int x) // 프로그램 시작 알림
{
	printf("%d명의 학생들의 이름과 성적을 입력받아 과목별 총점과 평균을 구하여 등수를 구하는 프로그램입니다.\n", x);
}
void END() // 출력되는 데이터의 정보를 알려준다
{
	printf("등수 이름   학번      국어 영어 수학 총점 평균\n");
}
void AVGPRINT(double x, double y, double z) // 국영수 학생들의 평균 점수 출력
{
	printf("국어 평균 : %g\n영어 평균 : %g\n수학 평균 : %g\n", x/STUDENT, y/STUDENT, z/STUDENT);
}
