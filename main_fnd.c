#include "main.h"
#include "fnd.h"
#include "led_sw.h"

/* 
//기본 예시 (배포된 코드 강의자료 예시 문제)
void main(void)
{
	int i;
	float fDispVal = -20.0;

	fnd_init();

	fnd_set(fDispVal);

	while(TRUE) {
		// fnd_show() 10회 호출 --> 약 50[msec]
		for(i=0; i<10; i++) fnd_show(); // 꾸준히 호출되어야 함
		fDispVal += 0.05;
		fnd_set(fDispVal);
	}
}


void main(void)
{
	int i;
	float fDispVal = 0;

	fnd_init();

	fnd_set(fDispVal);

	while(TRUE) {
		for(i=0; i<200; i++) fnd_show(); // 꾸준히 호출되어야 함
		fDispVal += 1;
		fnd_set(fDispVal);
	}
}

//실습과제 3-2
void main(void)
{
	int i;
	float fDispVal = 0;

	fnd_init();

	fnd_set(fDispVal);
	
	sw_init(); // 스위치가 연결된 포트 PE4와 PE5를 입력으로 설정
	int sw1_cnt = 0;

	while(TRUE) {
		if(sw_onoff(SW1)) { //SW1누르면 
			sw1_cnt++; //카운트 증가
		}
		if(sw1_cnt > 0){ //카운트가 증가하면
			for(i=0; i<200; i++) {
				fnd_show(); //1초마다 fnd에출력
				
				if(sw_onoff(SW1)){ //한번 더 sw1누르면
					while(TRUE){
						fnd_show(); //fnd출력 (일시정지 상태 출력)
						if(sw_onoff(SW1))break; //한번 더 누르면 두번쨰 while문 탈출 (일시정지 해제)
					}
				}
			}
			fDispVal += 1; //fnd출력 값 1증가
			fnd_set(fDispVal); //fnd에 증가된 값으로 설정
		}
	}
}
*/
//실습과제 3-2 sw_onoff(SW1)한번만 사용
void main(void)
{

	int icnt = 0;
	int iRun = FALSE;
	int isec = 0;
	sw_init(); // 스위치가 연결된 포트 PE4와 PE5를 입력으로 설정
	fnd_init();

	fnd_set(isec);
	while(TRUE) {
		if(sw_onoff(SW1)){
			iRun = !iRun; //iRun이 true -> false, false -> true 로 바꿈 
		}
		if(iRun){
			if(++icnt == 200){
				icnt = 0;
				isec += 1;
				fnd_set(isec);
			}
		}
		fnd_show();
	}
}