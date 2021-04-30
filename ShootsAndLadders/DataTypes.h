#ifndef DATATYPES_H_INCLUDED
#define DATATYPES_H_INCLUDED

using namespace std;

struct Player
{
    string name;
    int position;

};

class Board
{
    public:

        void setLevel1(int x)
        {
            level1=x;
        }

        int getLevel1()
        {
            return level1;
        }

        void setLevel2(int x)
        {
            level2=x;
        }

        int getLevel2()
        {
            return level2;
        }

        void setLevel3(int x)
        {
            level3=x;
        }

        int getLevel3()
        {
            return level3;
        }

        void setLevel4(int x)
        {
            level4=x;
        }

        int getLevel4()
        {
            return level4;
        }

        void setLevel5(int x)
        {
            level5=x;
        }

        int getLevel5()
        {
            return level5;
        }

        void setflag1(bool x)
        {
            flag1=x;
        }

        void setflag2(bool x)
        {
            flag2=x;
        }

        void setflag3(bool x)
        {
            flag3=x;
        }

        void setflag4(bool x)
        {
            flag4=x;
        }

        void setflag5(bool x)
        {
            flag5=x;
        }

        bool getflag1()
        {
            return flag1;
        }

        bool getflag2()
        {
            return flag2;
        }

        bool getflag3()
        {
            return flag3;
        }

        bool getflag4()
        {
            return flag1;
        }

        bool getflag5()
        {
            return flag5;
        }

    private:
        int level1, level2, level3, level4, level5;
        bool flag1, flag2, flag3, flag4, flag5;


};

class Snake{
    private:
        int snakeHead1, snakeHead2, snakeHead3, snakeHead4, snakeHead5;
        int snakeButt1, snakeButt2, snakeButt3, snakeButt4, snakeButt5;
    public:
        int getsnakeHead1()
        {
            return snakeHead1;
        }

        void setsnakeHead1(int x)
        {
            snakeHead1 = x;
        }
        int getsnakeHead2()
        {
            return snakeHead2;
        }

        void setsnakeHead2(int x)
        {
            snakeHead2 = x;
        }
        int getsnakeHead3()
        {
            return snakeHead3;
        }

        void setsnakeHead3(int x)
        {
            snakeHead3= x;
        }
        int getsnakeHead4()
        {
            return snakeHead4;
        }

        void setsnakeHead4(int x)
        {
            snakeHead4 = x;
        }
        int getsnakeHead5()
        {
            return snakeHead5;
        }

        void setsnakeHead5(int x)
        {
            snakeHead5=x;
        }

        int getsnakeButt1()
        {
            return snakeButt1;
        }

        void setsnakeButt1(int x)
        {
            snakeButt1 = x;
        }
        int getsnakeButt2()
        {
            return snakeButt2;
        }

        void setsnakeButt2(int x)
        {
            snakeButt2 = x;
        }
        int getsnakeButt3()
        {
            return snakeButt3;
        }

        void setsnakeButt3(int x)
        {
            snakeButt3= x;
        }
        int getsnakeButt4()
        {
            return snakeButt4;
        }

        void setsnakeButt4(int x)
        {
            snakeButt4 = x;
        }
        int getsnakeButt5()
        {
            return snakeButt5;
        }

        void setsnakeButt5(int x)
        {
            snakeButt5=x;
        }

};

class Ladder{
    private:
        int ladderTop1, ladderTop2, ladderTop3, ladderTop4, ladderTop5;
        int ladderBot1, ladderBot2, ladderBot3, ladderBot4, ladderBot5;
    public:
        int getladderTop1()
        {
            return ladderTop1;
        }

        void setladderTop1(int x)
        {
            ladderTop1 = x;
        }
        int getladderTop2()
        {
            return ladderTop2;
        }

        void setladderTop2(int x)
        {
            ladderTop2 = x;
        }
        int getladderTop3()
        {
            return ladderTop3;
        }

        void setladderTop3(int x)
        {
            ladderTop3= x;
        }
        int getladderTop4()
        {
            return ladderTop4;
        }

        void setladderTop4(int x)
        {
            ladderTop4 = x;
        }
        int getladderTop5()
        {
            return ladderTop5;
        }

        void setladderTop5(int x)
        {
            ladderTop5=x;
        }

        int getladderBot1()
        {
            return ladderBot1;
        }

        void setladderBot1(int x)
        {
            ladderBot1 = x;
        }
        int getladderBot2()
        {
            return ladderBot2;
        }

        void setladderBot2(int x)
        {
            ladderBot2 = x;
        }
        int getladderBot3()
        {
            return ladderBot3;
        }

        void setladderBot3(int x)
        {
            ladderBot3= x;
        }
        int getladderBot4()
        {
            return ladderBot4;
        }

        void setladderBot4(int x)
        {
            ladderBot4 = x;
        }
        int getladderBot5()
        {
            return ladderBot5;
        }

        void setladderBot5(int x)
        {
            ladderBot5 =x;
        }
};

#endif // DATATYPES_H_INCLUDED
