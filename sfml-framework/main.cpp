#include <SFML/Graphics.hpp>
#include "Framework/Framework.h"

int main()
{
    Framework framework(1280, 720);
    framework.Init();
    framework.Do();

    return 0;
}




// - ~~프레임웍 클래스
// - ~~씬 매니저
//      - 메뉴, 게임
// - ~~씬
//      - ~~게임 오브젝트 리스트
//      - ~~유아이 오브젝트 리스트
// - ~~오브젝트 클래스
//      - 스프라이트
//      - 유아이
//          - 이미지, 텍스트, 버튼 ...
// - 애니메이터
// - ~~데이터 테이블 매니저
// - 전역 변수 역할 클래스
// - 세이브 로드 매니저
// - ~~유틸리티 클래스
// - 사운드 매니저