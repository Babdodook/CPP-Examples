#include"CoreManager.h"

CoreManager::CoreManager()		//생성자에서 초기화
{
	LoginM = nullptr;
}

CoreManager::~CoreManager()		//소멸자에서 메모리 해제
{
	delete LoginM;
}

void CoreManager::Init()		//이니셜라이즈 함수에서 메모리 동적 할당
{
	LoginM = new LoginManager();
	LoginM->Init();				//로그인매니저가 소유하는 유저리스트 동적할당 하기위해 호출
}

void CoreManager::Run()
{
	Init();
	while (1)
	{
		switch (Mainmenu())
		{
		case MAINMENU::CREATE:		//회원가입
			LoginM->CreateAcc();	//로그인매니저 회원가입 메소드 호출
			break;
		case MAINMENU::LOGIN:		//로그인
			LoginM->Login();		//로그인매니저 로그인 메소드 호출
			break;
		case MAINMENU::EXIT:		//종료
			exit(1);
			break;
		default:
			cout << "잘못 입력하셨습니다" << endl;
			Clear();
			continue;
		}
	}
}

const int CoreManager::Mainmenu()	//메인메뉴 출력 메소드
{
	int select;
	cout << "<메뉴>" << endl;
	cout << "1. 회원가입" << endl;
	cout << "2. 로그인" << endl;
	cout << "3. 종료" << endl;
	cout << "선택: ";
	cin >> select;
	return select;
}