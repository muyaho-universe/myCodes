struct Score{
    int num;
    char name[20];
    int score[3];
    int sum;
    float avg;
};

int selectMenu();
struct Score* get_score(int count);
void readScore(struct Score *s[], int count);
struct Score* updateScore(int selectNum);
void deleteScore(struct Score *s[], int i, int count);
void searchData(struct Score *s[], int count);
int load_score(struct Score* p[], char* filename);
void save_score(struct Score* list[], char* filename, int count);