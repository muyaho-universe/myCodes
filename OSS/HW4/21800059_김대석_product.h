struct Product
{
    char name[20]; //제품명
    char description[100]; // 설명
    char weight[10]; // 중량
    int price;  // 가격
    int type;   // 배송방법
};

struct Product* get_product(int count); // 제품을 추가하는 함수
int readProduct(struct Product* p); // 하나의 제품 출력 함수
int listProduct(struct Product *p[], int count); // 전체 등록된 제품 리스트 출력
void searchProduct(struct Product *p[], int count, int type); // 제품이름 검색
int load_product(struct Product* p[], char* filename); // 제품정보가 저장된 파일 읽기/ type에 따라 검색의 내용이 달라짐
void save_product(struct Product* p[], char* filename, int count); // 파일에 제품 정보 저장
