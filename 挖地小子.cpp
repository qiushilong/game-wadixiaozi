#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include <tchar.h>     //TCHAR 版本字符串 
#pragma comment(lib,"Winmm.lib")
//#define _CRT_SECURE_NO_WARNINGS
#define HIGH 791
#define WIDTH 1200

struct Man
{
	int x;
	int y;
	int velocity;
	int blood;
	int blood_max;
	int oxygen;
	int oxygen_max;
	int num;  //挖掘力
	int num1;  //移动力
	int num2;   //保护力
	int iswudi;   //判断人是不是无敌
	int pose;//人物的形态
	int speak_live;   //是否说话
	int speak_num;  //说的那句话
};

struct Brick
{
	int x;
	int y;
	int blood;
	int contain;
};

struct Monster
{
	int x;
	int y;
	int blood;
	int z;//z表示怪物走的方向
	int velocity;
	int ishurt;//表示一个炸弹存在时是否受到伤害
};

struct Bag
{
	int money;
	int num; //急救药
	int num1;//氧气瓶
	int num2;//炸弹
	int num3;//普通矿
	int num4;//铜矿
	int num5;//银矿
	int num6;//金矿
	int num7;//水晶
	int num8;//钥匙
	int num9;//空位
};

struct Allnum
{
	int t1;
	int t2;
	int v2;//用来代替上升时的速度
	int is_only_one;//只执行一次
	int show_num;   //表示要显示的场景  0表示界面 1表示游戏 2表示boss房间
	int isgetshop;       //是否展开商店
	int isstatement;//是否展开游戏说明
	int v3;//下落时不让人物掉下去
};

IMAGE bk;
IMAGE man, man0, man1, man2, man3, man4, man5, man6, man7, man8, man9;
IMAGE man_z, man0_z, man1_z, man2_z, man3_z, man4_z, man5_z, man6_z, man7_z, man8_z, man9_z;
IMAGE brick0, brick1, brick2, brick4, brick3, brick5, brick6;
IMAGE jewel, jewel1, jewel2, jewel3, jewel4, jewel5;
IMAGE jewel_z, jewel1_z, jewel2_z, jewel3_z, jewel4_z, jewel5_z;
IMAGE monster0, monster1, monster2, monster3, monster4, monster5;
IMAGE monster0_z, monster1_z, monster2_z, monster3_z, monster4_z, monster5_z;
IMAGE bigmonster0, bigmonster1, bigmonster2, bigmonster3, bigmonster4, bigmonster5;
IMAGE bigmonster0_z, bigmonster1_z, bigmonster2_z, bigmonster3_z, bigmonster4_z, bigmonster5_z;
IMAGE shop, shop1, shop2, shop3, shop4, shop5;
IMAGE shop_z, shop1_z, shop2_z, shop3_z, shop4_z;
IMAGE data, data1;
IMAGE data_z, data1_z;
IMAGE bomb, bomb1, bomb2, bomb3, bomb4, bomb5, bomb6;
IMAGE bomb_z, bomb1_z, bomb2_z, bomb3_z, bomb4_z, bomb5_z, bomb6_z;
IMAGE wjewel, wjewel1, wjewel2, wjewel3, wjewel4;
IMAGE wjewel_z, wjewel1_z, wjewel2_z, wjewel3_z, wjewel4_z;
IMAGE x;
IMAGE speak, speak1;
IMAGE speak_z, speak1_z;
IMAGE door, door_z;
IMAGE Boss1, Boss2, Boss3, Boss4, Boss5, Boss6;
IMAGE Boss1_z, Boss2_z, Boss3_z, Boss4_z, Boss5_z, Boss6_z;
IMAGE cover, cover1;
IMAGE choose;
IMAGE frame, frame_z;
IMAGE statement;//说明是否展开
IMAGE story, story1, story2;
IMAGE victory_picture;
IMAGE fail;//失败时的图片
IMAGE key, key_z;

SYSTEMTIME ti;    //定义时间

struct Man xz;
struct Brick brick[422][64];
struct Monster monster[82], bigmonster[12], Boss[1];
struct Bag bag;
struct Allnum allnum;
int n;          //执行整个游戏的切图
int h;         //屏幕顶到土地的距离
int map_wz; //第一块砖的左边已过x=0的距离的负数
int shop_x, shop_y;
int bomb_x, bomb_y, bomb_live;
int bagposition[6][6];  //判断包的位置是不是满的
int door_x, door_y;
int short_map[19][21];

void loadimg()
{
	loadimage(&bk, L"image\\bk.png");
	loadimage(&man, L"image\\人物\\man.png");
	loadimage(&man0, L"image\\人物\\man0.png");
	loadimage(&man1, L"image\\人物\\man1.png");
	loadimage(&man2, L"image\\人物\\man2.png");
	loadimage(&man3, L"image\\人物\\man3.png");
	loadimage(&man4, L"image\\人物\\man4.png");
	loadimage(&man5, L"image\\人物\\man5.png");
	loadimage(&man6, L"image\\人物\\man6.png");
	loadimage(&man7, L"image\\人物\\man7.png");
	loadimage(&man8, L"image\\人物\\man8.png");
	loadimage(&man9, L"image\\人物\\man9.png");
	loadimage(&man_z, L"image\\人物\\man_z.png");
	loadimage(&man0_z, L"image\\人物\\man0_z.png");
	loadimage(&man1_z, L"image\\人物\\man1_z.png");
	loadimage(&man2_z, L"image\\人物\\man2_z.png");
	loadimage(&man3_z, L"image\\人物\\man3_z.png");
	loadimage(&man4_z, L"image\\人物\\man4_z.png");
	loadimage(&man5_z, L"image\\人物\\man5_z.png");
	loadimage(&man6_z, L"image\\人物\\man6_z.png");
	loadimage(&man7_z, L"image\\人物\\man7_z.png");
	loadimage(&man8_z, L"image\\人物\\man8_z.png");
	loadimage(&man9_z, L"image\\人物\\man9_z.png");
	loadimage(&brick0, L"image\\砖块\\brick.png");
	loadimage(&brick1, L"image\\砖块\\brick1.png");
	loadimage(&brick2, L"image\\砖块\\brick2.png");
	loadimage(&brick3, L"image\\砖块\\brick3.png");
	loadimage(&brick4, L"image\\砖块\\brick4.png");
	loadimage(&brick5, L"image\\砖块\\brick5.png");
	loadimage(&brick6, L"image\\砖块\\brick6.png");
	loadimage(&jewel, L"image\\宝物\\stone.png");
	loadimage(&jewel1, L"image\\宝物\\stone1.png");
	loadimage(&jewel2, L"image\\宝物\\stone2.png");
	loadimage(&jewel3, L"image\\宝物\\stone3.png");
	loadimage(&jewel4, L"image\\宝物\\stone4.png");
	loadimage(&jewel5, L"image\\宝物\\stone5.png");
	loadimage(&jewel_z, L"image\\宝物\\stone_z.png");
	loadimage(&jewel1_z, L"image\\宝物\\stone1_z.png");
	loadimage(&jewel2_z, L"image\\宝物\\stone2_z.png");
	loadimage(&jewel3_z, L"image\\宝物\\stone3_z.png");
	loadimage(&jewel4_z, L"image\\宝物\\stone4_z.png");
	loadimage(&jewel5_z, L"image\\宝物\\stone5_z.png");
	loadimage(&monster0, L"image\\怪物\\monster.png");
	loadimage(&monster1, L"image\\怪物\\monster1.png");
	loadimage(&monster2, L"image\\怪物\\monster2.png");
	loadimage(&monster3, L"image\\怪物\\monster3.png");
	loadimage(&monster4, L"image\\怪物\\monster4.png");
	loadimage(&monster5, L"image\\怪物\\monster5.png");
	loadimage(&monster0_z, L"image\\怪物\\monster_z.png");
	loadimage(&monster1_z, L"image\\怪物\\monster1_z.png");
	loadimage(&monster2_z, L"image\\怪物\\monster2_z.png");
	loadimage(&monster3_z, L"image\\怪物\\monster3_z.png");
	loadimage(&monster4_z, L"image\\怪物\\monster4_z.png");
	loadimage(&monster5_z, L"image\\怪物\\monster5_z.png");
	loadimage(&bigmonster0, L"image\\怪物\\bigmonster.png");
	loadimage(&bigmonster1, L"image\\怪物\\bigmonster1.png");
	loadimage(&bigmonster2, L"image\\怪物\\bigmonster2.png");
	loadimage(&bigmonster3, L"image\\怪物\\bigmonster3.png");
	loadimage(&bigmonster4, L"image\\怪物\\bigmonster4.png");
	loadimage(&bigmonster5, L"image\\怪物\\bigmonster5.png");
	loadimage(&bigmonster0_z, L"image\\怪物\\bigmonster_z.png");
	loadimage(&bigmonster1_z, L"image\\怪物\\bigmonster1_z.png");
	loadimage(&bigmonster2_z, L"image\\怪物\\bigmonster2_z.png");
	loadimage(&bigmonster3_z, L"image\\怪物\\bigmonster3_z.png");
	loadimage(&bigmonster4_z, L"image\\怪物\\bigmonster4_z.png");
	loadimage(&bigmonster5_z, L"image\\怪物\\bigmonster5_z.png");
	loadimage(&Boss1, L"image\\怪物\\boss1.png");
	loadimage(&Boss2, L"image\\怪物\\boss2.png");
	loadimage(&Boss3, L"image\\怪物\\boss3.png");
	loadimage(&Boss4, L"image\\怪物\\boss4.png");
	loadimage(&Boss5, L"image\\怪物\\boss5.png");
	loadimage(&Boss6, L"image\\怪物\\boss6.png");
	loadimage(&Boss1_z, L"image\\怪物\\boss1_z.png");
	loadimage(&Boss2_z, L"image\\怪物\\boss2_z.png");
	loadimage(&Boss3_z, L"image\\怪物\\boss3_z.png");
	loadimage(&Boss4_z, L"image\\怪物\\boss4_z.png");
	loadimage(&Boss5_z, L"image\\怪物\\boss5_z.png");
	loadimage(&Boss6_z, L"image\\怪物\\boss6_z.png");
	loadimage(&shop, L"image\\商店\\shop.png");
	loadimage(&shop1, L"image\\商店\\shop1.png");
	loadimage(&shop2, L"image\\商店\\shop2.png");
	loadimage(&shop3, L"image\\商店\\shop3.png");
	loadimage(&shop4, L"image\\商店\\shop4.png");
	loadimage(&shop5, L"image\\商店\\商店.png");
	loadimage(&shop_z, L"image\\商店\\shop_z.png");
	loadimage(&shop1_z, L"image\\商店\\shop1_z.png");
	loadimage(&shop2_z, L"image\\商店\\shop2_z.png");
	loadimage(&shop3_z, L"image\\商店\\shop3_z.png");
	loadimage(&shop4_z, L"image\\商店\\shop4_z.png");
	loadimage(&data, L"image\\状态\\状态栏.png");
	loadimage(&data1, L"image\\状态\\状态栏1.png");
	loadimage(&data_z, L"image\\状态\\状态栏_z.png");
	loadimage(&data1_z, L"image\\状态\\状态栏1_z.png");
	loadimage(&bomb, L"image\\物品\\bomb.png");
	loadimage(&bomb1, L"image\\物品\\bomb1.png");
	loadimage(&bomb2, L"image\\物品\\bomb2.png");
	loadimage(&bomb3, L"image\\物品\\bomb3.png");
	loadimage(&bomb4, L"image\\物品\\bomb4.png");
	loadimage(&bomb5, L"image\\物品\\bomb5.png");
	loadimage(&bomb6, L"image\\物品\\bomb6.png");
	loadimage(&bomb_z, L"image\\物品\\bomb_z.png");
	loadimage(&bomb1_z, L"image\\物品\\bomb1_z.png");
	loadimage(&bomb2_z, L"image\\物品\\bomb2_z.png");
	loadimage(&bomb3_z, L"image\\物品\\bomb3_z.png");
	loadimage(&bomb4_z, L"image\\物品\\bomb4_z.png");
	loadimage(&bomb5_z, L"image\\物品\\bomb5_z.png");
	loadimage(&bomb6_z, L"image\\物品\\bomb6_z.png");
	loadimage(&wjewel, L"image\\物品\\wjewel.png");
	loadimage(&wjewel1, L"image\\物品\\wjewel1.png");
	loadimage(&wjewel2, L"image\\物品\\wjewel2.png");
	loadimage(&wjewel3, L"image\\物品\\wjewel3.png");
	loadimage(&wjewel4, L"image\\物品\\wjewel4.png");
	loadimage(&wjewel_z, L"image\\物品\\wjewel_z.png");
	loadimage(&wjewel1_z, L"image\\物品\\wjewel1_z.png");
	loadimage(&wjewel2_z, L"image\\物品\\wjewel2_z.png");
	loadimage(&wjewel3_z, L"image\\物品\\wjewel3_z.png");
	loadimage(&wjewel4_z, L"image\\物品\\wjewel4_z.png");
	loadimage(&key, L"image\\物品\\key.png");
	loadimage(&key_z, L"image\\物品\\key_z.png");
	loadimage(&x, L"image\\物品\\x.png");
	loadimage(&speak, L"image\\speak\\speak.png");
	loadimage(&speak_z, L"image\\speak\\speak_z.png");
	loadimage(&speak1, L"image\\speak\\speak1.png");
	loadimage(&speak1_z, L"image\\speak\\speak1_z.png");
	loadimage(&door, L"image\\怪物\\door.png");
	loadimage(&door_z, L"image\\怪物\\door_z.png");
	loadimage(&cover, L"image\\界面\\cover.png");
	loadimage(&cover1, L"image\\界面\\cover1.png");
	loadimage(&choose, L"image\\界面\\choose.png");
	loadimage(&frame, L"image\\界面\\frame.png");
	loadimage(&frame_z, L"image\\界面\\frame_z.png");
	loadimage(&statement, L"image\\界面\\statement.png");
	loadimage(&story, L"image\\剧情\\story.png");
	loadimage(&story1, L"image\\剧情\\story1.png");
	loadimage(&story2, L"image\\剧情\\story2.png");
	loadimage(&victory_picture, L"image\\剧情\\victory.png");
	loadimage(&fail, L"image\\剧情\\fail.png");
}

void produce_jewel(int jewle_num, int up, int down, int b, int c)//生产宝石，按数量，宝石出现多的范围，宝石的种类，和从多少行开始
{
	int i, j, k;
	int num_x[5], num_y[5], num_s[5];
	for (k = 0; k < jewle_num; k++)
	{
		for (i = 0; i < 5; i++)
		{
			num_s[i] = 0;
			num_x[i] = 1 + rand() % 60 + 1;
			num_y[i] = c + rand() % (399 - c) + 1;
			while (brick[num_y[i]][num_x[i]].contain != 0 && brick[num_y[i]][num_x[i]].blood != 0)
			{
				num_x[i] = 1 + rand() % 60 + 1;
				num_y[i] = c + rand() % (399 - c) + 1;
			}
			if (num_y[i] >= up && num_y[i] <= down)
				num_s[i]++;
			if (brick[num_y[i] + 1][num_x[i]].contain == b)
				num_s[i]++;
			if (brick[num_y[i] - 1][num_x[i]].contain == b)
				num_s[i]++;
			if (brick[num_y[i]][num_x[i] + 1].contain == b)
				num_s[i]++;
			if (brick[num_y[i]][num_x[i] - 1].contain == b)
				num_s[i]++;
		}
		int max = num_s[0];
		j = 0;
		for (i = 1; i < 5; i++)
		{
			if (num_s[i] > max)
			{
				max = num_s[i];
				j = i;
			}
		}
		brick[num_y[j]][num_x[j]].contain = b;
	}
}

void produce_hole(int hole_num, int up, int down, int c, int hole_h, int hole_w)//按洞的数量，希望洞出现的范围，从多少层开始，洞高，洞宽输出洞
{
	int num_x[5], num_y[5], num_s[5];
	int i, j, k, l;
	for (l = 0; l < hole_num; l++)
	{
		for (i = 0; i < 5; i++)
		{
			num_s[i] = 0;
			num_y[i] = c + rand() % (399 - c) + 1;
			num_x[i] = 2 + rand() % 50 + 1;
			for (j = num_y[i] - 3; j < num_y[i] + hole_h + 3; j++)
				for (k = num_x[i] - 5; k < num_x[i] + hole_w + 5; k++)
					if (brick[j][k].blood == 0)
						num_s[i]--;
			if (num_y[i] > up && num_y[i] < down)
				num_s[i]++;
		}
		int max = num_s[0];
		j = 0;
		for (i = 1; i < 5; i++)
		{
			if (num_s[i] > max)
			{
				max = num_s[i];
				j = i;
			}
		}
		for (i = num_y[j]; i < num_y[j] + hole_h; i++)
			for (k = num_x[j]; k < num_x[j] + hole_w; k++)
			{
				if (brick[i][k].contain > 0 || brick[i][j].contain == -1)
					brick[i][k].contain = 0;
				brick[i][k].blood = 0;
			}
	}
}

void brick_xy()  //给每块砖定一个初始位置和血量以及含有的宝物
{
	int i, j;
	produce_jewel(3000, 1, 150, 1, 1);
	produce_jewel(2500, 75, 250, 2, 20);
	produce_jewel(2000, 200, 320, 3, 100);
	produce_jewel(1500, 250, 350, 4, 150);
	produce_jewel(1000, 300, 399, 5, 250);
	produce_jewel(1000, 200, 399, -1, 1);
	for (i = 0; i < 422; i++)
	{
		for (j = 0; j < 64; j++)
		{
			brick[i][j].x = 85 * j + map_wz;
			brick[i][j].y = 85 * i + h;
			brick[i][j].blood = 5;
			if (j == 0 || j == 1 || j == 62 || j == 63 || (i >= 400 && i <= 421))
				brick[i][j].contain = -1;
		}
	}
	for (i = 30; i < 37; i++)   //商店下的岩石
		brick[0][i].contain = -1;
	produce_hole(20, 15, 250, 15, 2, 7);
	produce_hole(20, 30, 300, 30, 2, 10);
	produce_hole(10, 120, 370, 120, 4, 10);
	for (i = 395; i < 400; i++)          //可进入Boss 房间
		for (j = 20; j < 40; j++)
		{
			if (brick[i][j].contain > 0 || brick[i][j].contain == -1)
				brick[i][j].contain = 0;
			brick[i][j].blood = 0;
		}
	for (i = 405; i < 415; i++)
		for (j = 20; j < 40; j++)
		{
			brick[i][j].blood = 0;
			brick[i][j].contain = 0;
		}
}

void monster_xy(int monster_n,int bigmonster_n)//把怪放进洞里并给他们一个初始血量	monster_n=0, bigmonster_n=0表示已经放置的怪物数
{
	int map_num();
	int i, j, k, l, c[422][64] = { 0 };        //c[422][64] 表示这个位置是否可以，是个flag
	for (i = 5; i < 395; i++)
	{
		for (j = 2; j < 64; j++)
		{
			if (brick[i][j].blood == 0 && c[i][j] == 0)
			{
				for (k = i;; k++)//测高度
				{
					if (brick[k][j].blood != 0)
						break;
				}
				for (l = j;; l++)//测长度
				{
					if (brick[i][l].blood != 0)
						break;
				}
				if (k - i == 2 && l - j == 7)
				{
					monster[monster_n].y = h + i * 85 /*+ rand() % 85 + 1*/;
					monster[monster_n].x = map_wz + (j + 1) * 85 + 150/* rand() % 200 + 1*/;
					monster_n++;
					for (k = i; k < i + 2; k++)
					{
						for (l = j; l < j + 7; l++)
						{
							c[k][l] = 1;
						}
					}
				}
				else if (k - i == 2 && l - j == 10)
				{
					monster[monster_n].y = h + i * 85 + rand() % 85 + 1;
					monster[monster_n].x = map_wz + (j + 1) * 85 + rand() % 510 + 1;
					monster[monster_n + 1].y = h + i * 85 + rand() % 85 + 1;
					monster[monster_n + 1].x = map_wz + (j + 1) * 85 + rand() % 510 + 1;
					monster_n += 2;
					for (k = i; k < i + 2; k++)
					{
						for (l = j; l < j + 10; l++)
						{
							c[k][l] = 1;
						}
					}
				}
				else if (k - i == 4 && l - j == 10)
				{
					monster[monster_n].y = h + i * 85 + rand() % 85 + 1;
					monster[monster_n].x = map_wz + (j + 1) * 85 + rand() % 510 + 1;
					monster[monster_n + 1].y = h + i * 85 + rand() % 85 + 1;
					monster[monster_n + 1].x = map_wz + (j + 1) * 85 + rand() % 510 + 1;
					monster_n += 2;
					bigmonster[bigmonster_n].y = h + i * 85 + rand() % 85 + 1;
					bigmonster[bigmonster_n].x = map_wz + (j + 1) * 85 + rand() % 350 + 1;
					bigmonster_n++;
					for (k = i; k < i + 4; k++)
					{
						for (l = j; l < j + 10; l++)
						{
							c[k][l] = 1;
						}
					}
				}
			}
		}
	}
	monster[monster_n].y = 33960; //Boss房间怪物
	monster[monster_n].x = 1800;
	bigmonster[10].y = 33960;
	bigmonster[10].x = 1970;
	monster[monster_n + 1].y = 33960;
	monster[monster_n + 1].x = 2140;
	bigmonster[11].y = 33960;
	bigmonster[11].x = 2310;
	for (i = 0; i < 82; i++)
		monster[i].blood = 100;
	for (i = 0; i < 12; i++)
		bigmonster[i].blood = 300;
	Boss[0].x = 35 * 85 + map_wz;
	Boss[0].y = 410 * 85 + h;
	Boss[0].blood = 3200;
}

void man_show()     //显示人物的不同形态
{
	if (xz.pose == 0) //站立
	{
		if (n % 2 == 0)
		{
			putimage(xz.x, xz.y, &man_z, SRCAND);
			putimage(xz.x, xz.y, &man, SRCPAINT);
		}
		if (n % 2 == 1)
		{
			putimage(xz.x, xz.y, &man0_z, SRCAND);
			putimage(xz.x, xz.y, &man0, SRCPAINT);
		}
	}
	else if (xz.pose == 1) //右走
	{
		if (n % 2 == 0)
		{
			putimage(xz.x, xz.y, &man3_z, SRCAND);
			putimage(xz.x, xz.y, &man3, SRCPAINT);
		}
		if (n % 2 == 1)
		{
			putimage(xz.x, xz.y, &man4_z, SRCAND);
			putimage(xz.x, xz.y, &man4, SRCPAINT);
		}
	}
	else if (xz.pose == 2)//左走
	{
		if (n % 2 == 0)
		{
			putimage(xz.x, xz.y, &man6_z, SRCAND);
			putimage(xz.x, xz.y, &man6, SRCPAINT);
		}
		if (n % 2 == 1)
		{
			putimage(xz.x, xz.y, &man7_z, SRCAND);
			putimage(xz.x, xz.y, &man7, SRCPAINT);
		}
	}
	else if (xz.pose == 3)   //右钻
	{
		putimage(xz.x, xz.y, &man5_z, SRCAND);
		putimage(xz.x, xz.y, &man5, SRCPAINT);
	}
	else if (xz.pose == 4)   //左钻
	{
		putimage(xz.x, xz.y, &man8_z, SRCAND);
		putimage(xz.x, xz.y, &man8, SRCPAINT);
	}
	else if (xz.pose == 5)  //下钻
	{
		putimage(xz.x, xz.y, &man1_z, SRCAND);
		putimage(xz.x, xz.y, &man1, SRCPAINT);
	}
	else if (xz.pose == 6)    //上升
	{
		putimage(xz.x, xz.y, &man2_z, SRCAND);
		putimage(xz.x, xz.y, &man2, SRCPAINT);
	}
	else if (xz.pose == 7)   //受伤
	{
		putimage(xz.x, xz.y, &man9_z, SRCAND);
		putimage(xz.x, xz.y, &man9, SRCPAINT);
	}
}

void brick_show(struct Brick(*brk)[64])
{
	int i, j;
	for (i = 0; i < 422; i++)
	{
		for (j = 0; j < 64; j++)
		{
			if (brk[i][j].x + 85 < 0 || brk[i][j].y + 85 < 0 || brk[i][j].x > WIDTH || brk[i][j].y > HIGH)
				continue;
			if (brk[i][j].blood ==5)
			{
				if (i == 0)
					putimage(brk[i][j].x, brk[i][j].y, &brick0);
				else
					putimage(brk[i][j].x, brk[i][j].y, &brick1);
			}
			else if (brk[i][j].blood ==4)
				putimage(brk[i][j].x, brk[i][j].y, &brick2);
			else if (brk[i][j].blood ==3)
				putimage(brk[i][j].x, brk[i][j].y, &brick3);
			else if (brk[i][j].blood ==2)
				putimage(brk[i][j].x, brk[i][j].y, &brick4);
			else if (brk[i][j].blood==1)
				putimage(brk[i][j].x, brk[i][j].y, &brick5);
			else if (brk[i][j].blood == 0)
				putimage(brk[i][j].x, brk[i][j].y, &brick6);
			if (brk[i][j].contain == -1)
			{
				putimage(brk[i][j].x, brk[i][j].y, &jewel_z, SRCAND);
				putimage(brk[i][j].x, brk[i][j].y, &jewel, SRCPAINT);
			}
			else if (brk[i][j].contain == 1)
			{
				putimage(brk[i][j].x, brk[i][j].y, &jewel1_z, SRCAND);
				putimage(brk[i][j].x, brk[i][j].y, &jewel1, SRCPAINT);
			}
			else if (brk[i][j].contain == 2)
			{
				putimage(brk[i][j].x, brk[i][j].y, &jewel2_z, SRCAND);
				putimage(brk[i][j].x, brk[i][j].y, &jewel2, SRCPAINT);
			}
			else if (brk[i][j].contain == 3)
			{
				putimage(brk[i][j].x, brk[i][j].y, &jewel3_z, SRCAND);
				putimage(brk[i][j].x, brk[i][j].y, &jewel3, SRCPAINT);
			}
			else if (brk[i][j].contain == 4)
			{
				putimage(brk[i][j].x, brk[i][j].y, &jewel4_z, SRCAND);
				putimage(brk[i][j].x, brk[i][j].y, &jewel4, SRCPAINT);
			}
			else if (brk[i][j].contain == 5)
			{
				putimage(brk[i][j].x, brk[i][j].y, &jewel5_z, SRCAND);
				putimage(brk[i][j].x, brk[i][j].y, &jewel5, SRCPAINT);
			}
		}
	}
}

void monster_show()
{
	int i;
	for (i = 0; i < 82; i++)
	{
		if (monster[i].blood <= 0)
			continue;
		if (monster[i].z == 1)
		{
			if (n % 3 == 0)
			{
				putimage(monster[i].x, monster[i].y, &monster0_z, SRCAND);
				putimage(monster[i].x, monster[i].y, &monster0, SRCPAINT);
			}
			else if (n % 3 == 1)
			{
				putimage(monster[i].x, monster[i].y, &monster1_z, SRCAND);
				putimage(monster[i].x, monster[i].y, &monster1, SRCPAINT);
			}
			else if (n % 3 == 2)
			{
				putimage(monster[i].x, monster[i].y, &monster2_z, SRCAND);
				putimage(monster[i].x, monster[i].y, &monster2, SRCPAINT);
			}
		}
		else if (monster[i].z == 0)
		{
			if (n % 3 == 0)
			{
				putimage(monster[i].x, monster[i].y, &monster3_z, SRCAND);
				putimage(monster[i].x, monster[i].y, &monster3, SRCPAINT);
			}
			else if (n % 3 == 1)
			{
				putimage(monster[i].x, monster[i].y, &monster4_z, SRCAND);
				putimage(monster[i].x, monster[i].y, &monster4, SRCPAINT);
			}
			else if (n % 3 == 2)
			{
				putimage(monster[i].x, monster[i].y, &monster5_z, SRCAND);
				putimage(monster[i].x, monster[i].y, &monster5, SRCPAINT);
			}
		}
	}
	for (i = 0; i < 12; i++)
	{
		if (bigmonster[i].blood <= 0)
			continue;
		if (bigmonster[i].z == 1)
		{
			if (n % 3 == 0)
			{
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster0_z, SRCAND);
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster0, SRCPAINT);
			}
			else if (n % 3 == 1)
			{
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster1_z, SRCAND);
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster1, SRCPAINT);
			}
			else if (n % 3 == 2)
			{
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster2_z, SRCAND);
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster2, SRCPAINT);
			}
		}
		else if (bigmonster[i].z == 0)
		{
			if (n % 3 == 0)
			{
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster3_z, SRCAND);
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster3, SRCPAINT);
			}
			else if (n % 3 == 1)
			{
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster4_z, SRCAND);
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster4, SRCPAINT);
			}
			else if (n % 3 == 2)
			{
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster5_z, SRCAND);
				putimage(bigmonster[i].x, bigmonster[i].y, &bigmonster5, SRCPAINT);
			}
		}
	}
	if (Boss[0].blood <= 0)
		return;
	if (Boss[0].z == 1)
	{
		if (n % 3 == 0)
		{
			putimage(Boss[0].x, Boss[0].y, &Boss1_z, SRCAND);
			putimage(Boss[0].x, Boss[0].y, &Boss1, SRCPAINT);
		}
		else if (n % 3 == 1)
		{
			putimage(Boss[0].x, Boss[0].y, &Boss2_z, SRCAND);
			putimage(Boss[0].x, Boss[0].y, &Boss2, SRCPAINT);
		}
		else if (n % 3 == 2)
		{
			putimage(Boss[0].x, Boss[0].y, &Boss3_z, SRCAND);
			putimage(Boss[0].x, Boss[0].y, &Boss3, SRCPAINT);
		}
	}
	else if (Boss[0].z == 0)
	{
		if (n % 3 == 0)
		{
			putimage(Boss[0].x, Boss[0].y, &Boss4_z, SRCAND);
			putimage(Boss[0].x, Boss[0].y, &Boss4, SRCPAINT);
		}
		else if (n % 3 == 1)
		{
			putimage(Boss[0].x, Boss[0].y, &Boss5_z, SRCAND);
			putimage(Boss[0].x, Boss[0].y, &Boss5, SRCPAINT);
		}
		else if (n % 3 == 2)
		{
			putimage(Boss[0].x, Boss[0].y, &Boss6_z, SRCAND);
			putimage(Boss[0].x, Boss[0].y, &Boss6, SRCPAINT);
		}
	}
	if ((xz.y + 42 - h) / 85 > 400)
	{
		rectangle(100, 100,900, 140);
		setfillcolor(RED);
		fillrectangle(100, 100, 100+Boss[0].blood/4, 140);
	}
}

void shop_show()
{
	if (n % 10 == 0 || n % 10 == 1)
	{
		putimage(shop_x, shop_y, &shop_z, SRCAND);
		putimage(shop_x, shop_y, &shop, SRCPAINT);
	}
	else if (n % 10 == 2 || n % 10 == 3)
	{
		putimage(shop_x, shop_y, &shop1_z, SRCAND);
		putimage(shop_x, shop_y, &shop1, SRCPAINT);
	}
	else if (n % 10 == 4 || n % 10 == 5)
	{
		putimage(shop_x, shop_y, &shop2_z, SRCAND);
		putimage(shop_x, shop_y, &shop2, SRCPAINT);
	}
	else if (n % 10 == 6 || n % 10 == 7)
	{
		putimage(shop_x, shop_y, &shop3_z, SRCAND);
		putimage(shop_x, shop_y, &shop3, SRCPAINT);
	}
	else if (n % 10 == 8 || n % 10 == 9)
	{
		putimage(shop_x, shop_y, &shop4_z, SRCAND);
		putimage(shop_x, shop_y, &shop4, SRCPAINT);
	}
}

void data_show()
{
	putimage(WIDTH - 815, 0, &data_z, SRCAND);
	putimage(WIDTH - 815, 0, &data, SRCPAINT);
	TCHAR s[10];
	setcolor(WHITE);
	_stprintf_s(s, L"%d", bag.num);
	outtextxy(WIDTH - 815 + 20, 50, s);
	_stprintf_s(s, L"%d", bag.num1);
	outtextxy(WIDTH - 815 + 85, 50, s);
	_stprintf_s(s, L"%d", bag.num2);
	outtextxy(WIDTH - 815 + 150, 50, s);
	rectangle(WIDTH - 815 + 598, 287, WIDTH - 815 + 598 + 160, 307);  //血条长160
	rectangle(WIDTH - 815 + 598, 351, WIDTH - 815 + 598 + 160, 371);
	setfillcolor(RED);
	fillrectangle(WIDTH - 815 + 598, 287, WIDTH - 815 + 598 + 160*xz.blood/xz.blood_max, 307);
	setfillcolor(BLUE);
	fillrectangle(WIDTH - 815 + 598, 351, WIDTH - 815 + 598 + 160*xz.oxygen / xz.oxygen_max, 371);
}

void bomb_show()
{
	if (bomb_live == 0)
		return;
	bomb_live++;
	if (bomb_live == 2)
		bag.num2--;
	if (bomb_live % 2 == 0 && bomb_live <= 20)
	{
		putimage(bomb_x, bomb_y, &bomb_z, SRCAND);
		putimage(bomb_x, bomb_y, &bomb, SRCPAINT);
	}
	else if (bomb_live % 2 == 1 && bomb_live <= 20)
	{
		putimage(bomb_x, bomb_y, &bomb1_z, SRCAND);
		putimage(bomb_x, bomb_y, &bomb1, SRCPAINT);
	}
	else if (bomb_live == 21)
	{
		putimage(bomb_x, bomb_y, &bomb2_z, SRCAND);
		putimage(bomb_x, bomb_y, &bomb2, SRCPAINT);
		mciSendString(L"close bombmusic", 0, 0, 0);
		mciSendString(L"open music\\bomb.mp3 alias bombmusic", 0, 0, 0);
		mciSendString(L"play bombmusic", 0, 0, 0);
	}
	else if (bomb_live == 22)
	{
		putimage(bomb_x, bomb_y, &bomb2_z, SRCAND);
		putimage(bomb_x, bomb_y, &bomb2, SRCPAINT);
	}
	else if (bomb_live == 23 || bomb_live == 24)
	{
		putimage(bomb_x, bomb_y, &bomb3_z, SRCAND);
		putimage(bomb_x, bomb_y, &bomb3, SRCPAINT);
	}
	else if (bomb_live == 25 || bomb_live == 26)
	{
		putimage(bomb_x, bomb_y, &bomb4_z, SRCAND);
		putimage(bomb_x, bomb_y, &bomb4, SRCPAINT);
	}
	else if (bomb_live == 27 || bomb_live == 28)
	{
		putimage(bomb_x, bomb_y, &bomb5_z, SRCAND);
		putimage(bomb_x, bomb_y, &bomb5, SRCPAINT);
	}
	else if (bomb_live == 29 || bomb_live == 30)
	{
		putimage(bomb_x, bomb_y, &bomb6_z, SRCAND);
		putimage(bomb_x, bomb_y, &bomb6, SRCPAINT);
		bomb_live = 0;
	}
}

void data1_show()
{
	putimage(0, 0, &data1_z, SRCAND);
	putimage(0, 0, &data1, SRCPAINT);
	TCHAR s[10];
	setcolor(WHITE);
	_stprintf_s(s, L"%d", xz.num + 1);
	outtextxy(220, 163, s);
	_stprintf_s(s, L"%d", xz.num1 + 1);
	outtextxy(220, 195, s);
	_stprintf_s(s, L"%d", xz.num2 + 1);
	outtextxy(220, 223, s);
	_stprintf_s(s, L"%d", xz.blood);
	outtextxy(193, 61, s);
	_stprintf_s(s, L"%d", xz.oxygen);
	outtextxy(193, 94, s);
}

void bag_show()
{
	void bag_count();
	int i, j;
	TCHAR s[20];
	_stprintf_s(s, L"%d", bag.money);
	outtextxy(335, 263, s);
	bag_count();
	int num3 = bag.num3, num4 = bag.num4, num5 = bag.num5, num6 = bag.num6, num7 = bag.num7,num8=bag.num8, num9 = bag.num9;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
		{
			if (num9 > 0)
			{
				bagposition[i][j] = 0;
				num9--;
			}
		}
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (bagposition[i][j] == 0)
			{
				if (num8 > 0)
				{
					putimage(60, 310, &key_z, SRCAND);
					putimage(60 , 310 , &key, SRCPAINT);
					num8--;
					bagposition[i][j] = 2;
					continue;
				}
				if (num3 >= 10)
				{
					putimage(66 + j * 68, 315 + i * 68, &wjewel_z, SRCAND);
					putimage(66 + j * 68, 315 + i * 68, &wjewel, SRCPAINT);
					_stprintf_s(s, L"%d", 10);
					outtextxy(63 + j * 68, i * 68 + 315, s);
					num3 -= 10;
					bagposition[i][j] = 2;
					continue;
				}
				else if (num3 > 0 && num3 < 10)
				{
					putimage(66 + j * 68, 315 + i * 68, &wjewel_z, SRCAND);
					putimage(66 + j * 68, 315 + i * 68, &wjewel, SRCPAINT);
					_stprintf_s(s, L"%d", num3);
					outtextxy(63 + j * 68, i * 68 + 315, s);
					num3 = 0;
					bagposition[i][j] = 2;
					continue;
				}
				if (num4 >= 10)
				{
					putimage(66 + j * 68, 315 + i * 68, &wjewel1_z, SRCAND);
					putimage(66 + j * 68, 315 + i * 68, &wjewel1, SRCPAINT);
					_stprintf_s(s, L"%d", 10);
					outtextxy(63 + j * 68, i * 68 + 315, s);
					num4 -= 10;
					bagposition[i][j] = 2;
					continue;
				}
				else if (num4 > 0 && num4 < 10)
				{
					putimage(66 + j * 68, 315 + i * 68, &wjewel1_z, SRCAND);
					putimage(66 + j * 68, 315 + i * 68, &wjewel1, SRCPAINT);
					_stprintf_s(s, L"%d", num4);
					outtextxy(63 + j * 68, i * 68 + 315, s);
					num4 = 0;
					bagposition[i][j] = 2;
					continue;
				}
				if (num5 >= 10)
				{
					putimage(66 + j * 68, 315 + i * 68, &wjewel2_z, SRCAND);
					putimage(66 + j * 68, 315 + i * 68, &wjewel2, SRCPAINT);
					_stprintf_s(s, L"%d", 10);
					outtextxy(63 + j * 68, i * 68 + 315, s);
					num5 -= 10;
					bagposition[i][j] = 2;
					continue;
				}
				else if (num5 > 0 && num5 < 10)
				{
					putimage(66 + j * 68, 315 + i * 68, &wjewel2_z, SRCAND);
					putimage(66 + j * 68, 315 + i * 68, &wjewel2, SRCPAINT);
					_stprintf_s(s, L"%d", num5);
					outtextxy(63 + j * 68, i * 68 + 315, s);
					num5 = 0;
					bagposition[i][j] = 2;
					continue;
				}
				if (num6 >= 10)
				{
					putimage(66 + j * 68, 315 + i * 68, &wjewel3_z, SRCAND);
					putimage(66 + j * 68, 315 + i * 68, &wjewel3, SRCPAINT);
					_stprintf_s(s, L"%d", 10);
					outtextxy(63 + j * 68, i * 68 + 315, s);
					num6 -= 10;
					bagposition[i][j] = 2;
					continue;
				}
				else if (num6 > 0 && num6 < 10)
				{
					putimage(66 + j * 68, 315 + i * 68, &wjewel3_z, SRCAND);
					putimage(66 + j * 68, 315 + i * 68, &wjewel3, SRCPAINT);
					_stprintf_s(s, L"%d", num6);
					outtextxy(63 + j * 68, i * 68 + 315, s);
					num6 = 0;
					bagposition[i][j] = 2;
					continue;
				}
				if (num7 >= 10)
				{
					putimage(66 + j * 68, 315 + i * 68, &wjewel4_z, SRCAND);
					putimage(66 + j * 68, 315 + i * 68, &wjewel4, SRCPAINT);
					_stprintf_s(s, L"%d", 10);
					outtextxy(63 + j * 68, i * 68 + 315, s);
					num7 -= 10;
					bagposition[i][j] = 2;
					continue;
				}
				else if (num7 > 0 && num7 < 10)
				{
					putimage(66 + j * 68, 315 + i * 68, &wjewel4_z, SRCAND);
					putimage(66 + j * 68, 315 + i * 68, &wjewel4, SRCPAINT);
					_stprintf_s(s, L"%d", num7);
					outtextxy(63 + j * 68, i * 68 + 315, s);
					num7 = 0;
					bagposition[i][j] = 2;
					continue;
				}
			}
			else if (bagposition[i][j] == 1)
				putimage(60 + j * 68, 305 + i * 68, &x);
		}
	}
}

void speak_show()
{
	if (xz.speak_live == 0)
		return;
	if (xz.speak_num == 1)
	{
		if (xz.speak_live < 7)
		{
			putimage(xz.x - 120, xz.y - 200, &speak_z, SRCAND);
			putimage(xz.x - 120, xz.y - 200, &speak, SRCPAINT);
		}
		if (xz.speak_live == 7)
		{
			putimage(xz.x - 120, xz.y - 200, &speak_z, SRCAND);
			putimage(xz.x - 120, xz.y - 200, &speak, SRCPAINT);
			xz.speak_live = -1;
		}
	}
	else if (xz.speak_num == 2)
	{
		if (xz.speak_live < 7)
		{
			putimage(xz.x - 120, xz.y - 200, &speak1_z, SRCAND);
			putimage(xz.x - 120, xz.y - 200, &speak1, SRCPAINT);
		}
		if (xz.speak_live == 7)
		{
			putimage(xz.x - 120, xz.y - 200, &speak1_z, SRCAND);
			putimage(xz.x - 120, xz.y - 200, &speak1, SRCPAINT);
			xz.speak_live = -1;
		}
	}
	xz.speak_live++;
}

void num_show()
{

}

void door_show()
{
	putimage(door_x, door_y, &door_z, SRCAND);
	putimage(door_x, door_y, &door, SRCPAINT);
}

void shortmap_show()
{
	int i, j;
	int map_num();
	int map_num1();
	short_map[9][11] = 2;//表示人
	for (i = 0; i < 19; i++)
		for (j = 0; j < 21; j++)
		{
			if (i == 9 && j == 11)
				continue;
			if (((xz.y + 95) - h) / 85 + (i - 10) < 0 || (xz.x + 42 - map_num1()) / 85 - map_num() - 1 + (j - 10) < 0)//不能越界
			{
				short_map[i][j] = 0;
				continue;
			}
			if (brick[((xz.y + 95) - h) / 85 + (i - 10)][(xz.x + 42 - map_num1()) / 85 - map_num() - 1 + (j - 10)].blood > 0)
				short_map[i][j] = 1;//表示有砖块
			else
				short_map[i][j] = 0;//表示无砖块
		}
	for (i = 0; i < 19; i++)
		for (j = 0; j < 21; j++)
		{
			if (short_map[i][j] == 0)
			{
				setfillcolor(YELLOW);
				bar(WIDTH - 815 + 571 + 10 * j, 33 + 10 * i, WIDTH - 815 + 581 + 10 * j, 43 + 10 * i);
			}
			else if (short_map[i][j] == 1)
			{
				setfillcolor(GREEN);
				bar(WIDTH - 815 + 571 + 10 * j, 33 + 10 * i, WIDTH - 815 + 581 + 10 * j, 43 + 10 * i);
			}
			else if (short_map[i][j] == 2)
			{
				if (n % 6 > 3)
					setfillcolor(BLUE);
				else
					setfillcolor(RED);
				bar(WIDTH - 815 + 571 + 10 * j, 33 + 10 * i, WIDTH - 815 + 581 + 10 * j, 43 + 10 * i);
			}
		}
	TCHAR s[10];
	_stprintf_s(s, L"%d", ((xz.y + 95) - h) / 85);//将整形a转换成字符串
	_tcscat_s(s, L"层");
	setbkmode(TRANSPARENT);//字体背景设为透明       一个使全部都变透明了
	setcolor(BLACK);//字体为黑色
	outtextxy(WIDTH - 815 + 700, 222, s);//将字符串输出到界面上
}

void control_mouse()
{
	FlushMouseMsgBuffer();// 清除鼠标数据缓存
	MOUSEMSG msg;
	msg = GetMouseMsg();
	if (msg.y > 195 && msg.y<255 && msg.x>WIDTH - 517 && msg.x < WIDTH - 367 && allnum.isgetshop == 10)//一键出售
	{
		mciSendString(L"close tapmusic", 0, 0, 0);
		mciSendString(L"open music\\tap.mp3 alias tapmusic", 0, 0, 0);
		mciSendString(L"play tapmusic", 0, 0, 0);
		bag.money = bag.money + 25 * bag.num3 + 50 * bag.num4 + 100 * bag.num5 + 200 * bag.num6 + 400 * bag.num7;
		bag.num3 = 0;
		bag.num4 = 0;
		bag.num5 = 0;
		bag.num6 = 0;
		bag.num7 = 0;
	}
	if (msg.y > 296 && msg.y < 353)    //第一行
	{
		if (msg.x > WIDTH - 583 + 17 && msg.x < WIDTH - 583 + 17 + 159 && bag.money >= 1000)//急救包    //第一列
		{
			mciSendString(L"close tapmusic", 0, 0, 0);
			mciSendString(L"open music\\tap.mp3 alias tapmusic", 0, 0, 0);
			mciSendString(L"play tapmusic", 0, 0, 0);
			bag.money -= 1000;
			bag.num++;
		}
		else	if (msg.x > WIDTH - 583 + 181 && msg.x < WIDTH - 583 + 181 + 159 && bag.money >= 500)//氧气  第二列
		{
			mciSendString(L"close tapmusic", 0, 0, 0);
			mciSendString(L"open music\\tap.mp3 alias tapmusic", 0, 0, 0);
			mciSendString(L"play tapmusic", 0, 0, 0);
			bag.money -= 500;
			bag.num1++;
		}
	}
	else if (msg.y > 347 && msg.y < 404)//炸弹   第二行
	{
		if (msg.x > WIDTH - 583 + 17 && msg.x < WIDTH - 583 + 17 + 159 && bag.money >= 100)
		{
			mciSendString(L"close tapmusic", 0, 0, 0);
			mciSendString(L"open music\\tap.mp3 alias tapmusic", 0, 0, 0);
			mciSendString(L"play tapmusic", 0, 0, 0);
			bag.money -= 100;
			bag.num2++;
		}
	}
	else if (msg.y > 435 && msg.y < 493)
	{
		if (msg.x > WIDTH - 583 + 361 && msg.x < WIDTH - 583 + 361 + 159 && bag.money >= 1000)//第三列
		{
			mciSendString(L"close tapmusic", 0, 0, 0);
			mciSendString(L"open music\\tap.mp3 alias tapmusic", 0, 0, 0);
			mciSendString(L"play tapmusic", 0, 0, 0);
			bag.money -= 1000;
			bag.num9++;
		}
	}
	else if (msg.y > 507 && msg.y < 564)   //第四行
	{
		if (msg.x > WIDTH - 583 + 17 && msg.x < WIDTH - 583 + 17 + 159 && bag.money >= 100000 && bag.num8 == 0)//钥匙
		{
			mciSendString(L"close tapmusic", 0, 0, 0);
			mciSendString(L"open music\\tap.mp3 alias tapmusic", 0, 0, 0);
			mciSendString(L"play tapmusic", 0, 0, 0);
			bag.money -= 100000;
			bag.num8++;
		}
		else if (msg.x > WIDTH - 583 + 361 && msg.x < WIDTH - 583 + 361 + 159 && bag.money >= 2000&&xz.num<9)//挖掘力 
		{
			mciSendString(L"close tapmusic", 0, 0, 0);
			mciSendString(L"open music\\tap.mp3 alias tapmusic", 0, 0, 0);
			mciSendString(L"play tapmusic", 0, 0, 0);
			bag.money -= 2000;
			xz.num++;
		}
	}
	else if (msg.y > 578 && msg.y < 635)//第五行
	{
		if (msg.x > WIDTH - 583 + 17 && msg.x < WIDTH - 583 + 17 + 159 && bag.money >= 2000 && xz.num1 < 14)//移动力
		{
			mciSendString(L"close tapmusic", 0, 0, 0);
			mciSendString(L"open music\\tap.mp3 alias tapmusic", 0, 0, 0);
			mciSendString(L"play tapmusic", 0, 0, 0);
			bag.money -= 2000;
			xz.num1++;
		}
		else	if (msg.x > WIDTH - 583 + 181 && msg.x < WIDTH - 583 + 181 + 159 && bag.money >= 2000 && xz.num2 < 9)//防御力   
		{
			mciSendString(L"close tapmusic", 0, 0, 0);
			mciSendString(L"open music\\tap.mp3 alias tapmusic", 0, 0, 0);
			mciSendString(L"play tapmusic", 0, 0, 0);
			xz.blood += 10;
			xz.oxygen += 100;
			xz.blood_max += 10;
			xz.oxygen_max += 100;
			bag.money -= 2000;
			xz.num2++;
		}
	}
	else if (msg.y > 668 && msg.y < 729)
	{
		if (msg.x > WIDTH - 583 + 114 && msg.x < WIDTH - 583 + 272)
		{
			mciSendString(L"close tapmusic", 0, 0, 0);
			mciSendString(L"open music\\tap.mp3 alias tapmusic", 0, 0, 0);
			mciSendString(L"play tapmusic", 0, 0, 0);
			void save_data();
			save_data();
		}
		else if (msg.x > WIDTH - 583 + 376 && msg.x < WIDTH - 583 + 529)
		{
			mciSendString(L"close tapmusic", 0, 0, 0);
			mciSendString(L"open music\\tap.mp3 alias tapmusic", 0, 0, 0);
			mciSendString(L"play tapmusic", 0, 0, 0);
			allnum.isgetshop = 0;
		}
	}
}

int map_num()//用来记对应砖块需要加的数字
{
	if (map_wz % 85 == 0)
		return map_wz / 85 - 1;
	else
		return map_wz / 85 - 1;
}

int map_num1()             //计算图上第一块砖左边到y=0的距离
{
	if (map_wz == 0)
		return 0;
	else
		return 85 + map_wz % 85;
}

int get_h()    //get_h()表示xz.x对应草坪到砖块的距离
{
	int high, i;
	if (xz.y + 95 < h)
	{
		for (i = 0; i < 422; i++)
		{
			if (brick[i][(xz.x + 42 - map_num1()) / 85 - map_num()].blood > 0)
			{
				high = i * 85;
				return high;
			}
		}
	}
	for (i = ((xz.y + 95) - h) / 85; i < 422; i++)
	{
		if (brick[i][(xz.x + 42 - map_num1()) / 85 - map_num()].blood > 0)
		{
			high = i * 85;
			return high;
		}
	}
}

int get_wr()                    //get_wr()表示人右边第一块的左侧砖到x=0的距离
{
	int width, j;
	if (xz.y + 95 <= h)
		return 5270;
	for (j = (xz.x + 42 - map_num1()) / 85 - map_num() + 1; j < 64; j++)
	{
		if (brick[(xz.y + 47 - h) / 85][j].blood > 0)
		{
			width = (j + map_num()) * 85 + map_num1();
			return width;
		}
	}
}

int get_wl()  //get_wl()表示人左边第一块砖的右侧到x=0的距离
{
	int width, j;
	if (xz.y + 95 <= h)
		return 15;
	for (j = (xz.x + 42 - map_num1()) / 85 - map_num() - 1; j >= 0; j--)
	{
		if (brick[(xz.y + 47 - h) / 85][j].blood > 0)
		{
			width = (j + 1 + map_num()) * 85 + map_num1();
			return width;
		}
	}
}

int get_up() //求小人上面一块砖到x=0的距离
{
	int high, j;
	if (xz.y + 90 < h)
		return -1;
	for (j = (xz.y + 47 - h) / 85 - 1; j >= 0; j--)
	{
		if (brick[j][(xz.x + 42 - map_num1()) / 85 - map_num()].blood > 0)
		{
			return h + 85 * (j + 1);
		}
	}
}

void fly()
{
	void map_upchange();
	if (xz.velocity > -64)
		xz.velocity -= 10+xz.num1/2;
	if (xz.y + 10 > get_up() && get_up() != -1)
	{
		if (xz.y + 10 + xz.velocity > get_up())
		{
			if (xz.y > 200)
				xz.y = xz.y + xz.velocity;
			else
				map_upchange();
		}
		else
		{
			xz.y = get_up();
			xz.velocity = 0;
		}
	}
	if (get_up() == -1)
	{
		if (xz.y > 200)
			xz.y = xz.y + xz.velocity;
		else
		{
			map_upchange();
		}
	}
	xz.pose = 6;
}

void fall()
{
	void map_downchange();
	if (xz.y + 95 - get_h() < h)
	{
		if (xz.velocity < 50)
			if (allnum.is_only_one == 0)
				xz.velocity += 10;
			else
				xz.velocity = 0;
		if (xz.y + xz.velocity + 95 - get_h() > h)
		{
			allnum.v3 = h + get_h() - xz.y - 95;
			xz.y = h - 95 + get_h();
			xz.velocity = 0;
		}
		else
		{
			if (xz.y < 500)
				xz.y = xz.y + xz.velocity;
			else
			{
				map_downchange();
			}
		}
	}
	else
		xz.velocity = 0;
	Sleep(30 - 2 * xz.num1);
}

void monster_fall(struct Monster guai[], int monster_num, int monster_h, int monster_w)
{
	int mh = 0, i, j, k;
	for (k = 0; k < monster_num; k++)
	{
		for (i = ((guai[k].y + monster_h) - h) / 85; i < 422; i++)
		{
			if (brick[i][(guai[k].x + monster_w / 2 - map_num1()) / 85 - map_num()].blood > 0)
			{
				mh = i * 85;
				break;
			}
		}
		if (guai[k].y + monster_h - mh < h)
		{
			if (guai[k].velocity < 30)
				guai[k].velocity += 10;
			if (guai[k].y + guai[k].velocity + monster_h - mh > h)
			{
				guai[k].y = h - monster_h + mh;
				guai[k].velocity = 0;
			}
			else
				guai[k].y = guai[k].y + guai[k].velocity;
		}
		if (guai[k].y + monster_h - mh > h)     //把怪物挤出去
			guai[k].y = h - monster_h + mh;
	}
}

void monster_move(struct Monster guai[], int monster_num, int monster_h, int monster_w)
{
	int i, j, k;
	int mw0 = 0, mw1 = 0;    //表示到左右砖的距离   [(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num() + 1]
	for (k = 0; k < monster_num; k++)
	{
		for (j = (guai[k].x + monster_w / 2 - map_num1()) / 85 - map_num() + 1; j < 64; j++)
		{
			if (brick[(guai[k].y + monster_h / 2 - h) / 85][j].blood > 0)
			{
				mw1 = (j - 1 + map_num()) * 85 + map_num1();
				break;
			}
		}
		for (j = (guai[k].x + monster_w / 2 - map_num1()) / 85 - map_num() - 1; j >= 0; j--)
		{
			if (brick[(guai[k].y + monster_h / 2 - h) / 85][j].blood > 0)
			{
				mw0 = (j + 1 + map_num()) * 85 + map_num1();
				break;
			}
		}
		if (guai[k].z == 1)
		{
			if (guai[k].x + monster_w - 10 < mw1)
				guai[k].x += 10;
			else
				guai[k].z = 0;
		}
		else
		{
			if (guai[k].x > mw0)
				guai[k].x -= 10;
			else
				guai[k].z = 1;
		}
	}
}

void monster_kill()
{
	if (bomb_live <= 20)
		return;
	int i;
	for (i = 0; i < 82; i++)
	{
		if (bomb_y + 30 > monster[i].y && bomb_y + 30 < monster[i].y + 85 && ((bomb_x - 20 < monster[i].x + 75 && bomb_x - 20 > monster[i].x)
			|| (bomb_x + 63 + 20 > monster[i].x && bomb_x + 63 + 20 < monster[i].x + 75)) && monster[i].ishurt == 0)
		{
			monster[i].ishurt = 1;
			monster[i].blood -= 100;
			if (monster[i].blood == 0)
			{
				mciSendString(L"close getjewelmusic", 0, 0, 0);
				mciSendString(L"open music\\getjewel.mp3 alias getjewelmusic", 0, 0, 0);
				mciSendString(L"play getjewelmusic", 0, 0, 0);
				outtextxy(monster[i].x + 30, monster[i].y - 10, L"+300");
				bag.money += 300;
			}
		}
	}
	for (i = 0; i < 12; i++)
	{
		if (bomb_y + 30 > bigmonster[i].y && bomb_y + 30 < bigmonster[i].y + 175 && ((bomb_x - 20 < bigmonster[i].x + 185 && bomb_x - 20 > bigmonster[i].x)
			|| (bomb_x + 63 + 20 > bigmonster[i].x && bomb_x + 63 + 20 < bigmonster[i].x + 185)) && bigmonster[i].ishurt == 0)
		{
			bigmonster[i].ishurt = 1;
			bigmonster[i].blood -= 100;
			if (bigmonster[i].blood == 0)
			{
				mciSendString(L"close getjewelmusic", 0, 0, 0);
				mciSendString(L"open music\\getjewel.mp3 alias getjewelmusic", 0, 0, 0);
				mciSendString(L"play getjewelmusic", 0, 0, 0);
				outtextxy(bigmonster[i].x + 30, bigmonster[i].y - 10, L"+1000");
				bag.money += 1000;
			}

		}
	}
	if (bomb_y + 30 > Boss[0].y && bomb_y + 30 < Boss[0].y + 405 && ((bomb_x - 20 < Boss[0].x + 355 && bomb_x - 20 > Boss[0].x)
		|| (bomb_x + 63 + 20 > Boss[0].x && bomb_x + 63 + 20 < Boss[0].x + 355)) && Boss[0].ishurt == 0)
	{
		{
			Boss[0].ishurt = 1;
			Boss[0].blood -= 100;
		}
	}
}

void getin_bossroom()
{
	void bossroom();
	TCHAR s[10];
	if (xz.y + 95 == door_y + 210 && ((xz.x + 85 > door_x + 45 && xz.x + 85 < door_x + 310 - 45)
		|| (xz.x > door_x + 45 && xz.x < door_x + 310 - 45)) && bag.num8 == 1)
	{
		bossroom();
	}
	else if (xz.y + 95 == door_y + 210 && ((xz.x + 85 > door_x + 45 && xz.x + 85 < door_x + 310 - 45)
		|| (xz.x > door_x + 45 && xz.x < door_x + 310 - 45)) && bag.num8 == 0)
	{
		xz.speak_live = 1;
		xz.speak_num = 2;
	}
}

void bossroom()
{
	int i, j;
	for (i = 0; i < 422; i++)
	{
		for (j = 0; j < 64; j++)
		{
			brick[i][j].y -= 85 * 15;
		}
	}
	h -= 85 * 15;
	for (i = 0; i < 82; i++)
		monster[i].y -= 85 * 15;
	for (i = 0; i < 12; i++)
		bigmonster[i].y -= 85 * 15;
	shop_y -= 85 * 15;
	bomb_y -= 85 * 15;
	door_y -= 85 * 15;
	Boss[0].y -= 85 * 15;
}

void crow_brick()   //把人物挤出砖块
{
	if (xz.y + 95 - get_h() > h)
		xz.y = h - 95 + get_h();
	if (xz.y + 10 < get_up() && get_up() != -1)
	{
		xz.y = get_up() - 10;
		xz.velocity = 0;
	}
	/*if (GetAsyncKeyState(VK_LEFT) & 0x8000&&xz.x > get_wl())
		xz.x = get_wl();
	if (GetAsyncKeyState('D') & 0x8000&&xz.x > get_wr())
		xz.x = get_wr()-65;*/
}

void down_dig()
{
	xz.pose = 5;
	//shake();
	if (brick[((xz.y + 95) - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].blood - 1 >= 0
		&& brick[(xz.y + 95 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain != -1)
		brick[((xz.y + 95) - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].blood--;
	Sleep(20-2*xz.num);//挖掘力升级
}

void left_dig()
{
	xz.pose = 4;
	//shake();
	if (brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num() - 1].blood - 1 >= 0
		&& brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num() - 1].contain != -1)
		brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num() - 1].blood--;
	Sleep(20 - 2* xz.num);
}

void right_dig()
{
	xz.pose = 3;
	//shake();
	if (brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num() + 1].blood - 1 >= 0
		&& brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num() + 1].contain != -1)
		brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num() + 1].blood--;
	Sleep(20 - 2 * xz.num);
}

void map_leftchange()
{
	if (map_wz > -5425 + WIDTH)
		map_wz -= 5 + xz.num1;
	else
	{
		if (xz.x < WIDTH - 85)
			xz.x += 5 + xz.num1;
		return;
	}
	int i, j;
	for (i = 0; i < 422; i++)
	{
		for (j = 0; j < 64; j++)
		{
			brick[i][j].x -= 5 + xz.num1;
		}
	}
	for (i = 0; i < 82; i++)
		monster[i].x -= 5 + xz.num1;
	for (i = 0; i < 12; i++)
		bigmonster[i].x -= 5 + xz.num1;
	Boss[0].x -= 5 + xz.num1;
	shop_x -= 5 + xz.num1;
	bomb_x -= 5 + xz.num1;
	door_x -= 5 + xz.num1;
}

void map_rightchange()
{
	if (map_wz < 0)
		map_wz += 5+xz.num1;
	else
	{
		xz.x -= 5 + xz.num1;
		return;
	}
	int i, j;
	for (i = 0; i < 422; i++)
	{
		for (j = 0; j < 64; j++)
		{
			brick[i][j].x += 5 + xz.num1;
		}
	}
	for (i = 0; i < 82; i++)
		monster[i].x += 5 + xz.num1;
	for (i = 0; i < 12; i++)
		bigmonster[i].x += 5 + xz.num1;
	Boss[0].x += 5 + xz.num1;
	shop_x += 5 + xz.num1;
	bomb_x += 5 + xz.num1;
	door_x += 5 + xz.num1;
}

void map_downchange()
{
	h -= xz.velocity + allnum.v3;
	int i, j;
	for (i = 0; i < 422; i++)
	{
		for (j = 0; j < 64; j++)
		{
			brick[i][j].y -= xz.velocity+allnum.v3;
		}
	}
	for (i = 0; i < 82; i++)
		monster[i].y -= xz.velocity + allnum.v3;
	for (i = 0; i < 12; i++)
		bigmonster[i].y -= xz.velocity + allnum.v3;
	Boss[0].y -= xz.velocity + allnum.v3;
	shop_y -= xz.velocity + allnum.v3;
	bomb_y -= xz.velocity + allnum.v3;
	door_y -= xz.velocity + allnum.v3;
}

void map_upchange()
{
	if (allnum.is_only_one == 0)//只执行一次
	{
		allnum.v2 = xz.velocity;
		allnum.is_only_one = 1;
	}
	xz.velocity = 0;
	if (allnum.v2 > -44)
		allnum.v2 -= 10 + xz.num1 / 2;
	if (xz.y + 10 + allnum.v2 < get_up() && get_up() != -1)
	{
		xz.y = get_up();
		allnum.v2 = 0;
	}

	h -= allnum.v2;
	int i, j;
	for (i = 0; i < 422; i++)
	{
		for (j = 0; j < 64; j++)
		{
			brick[i][j].y -= allnum.v2;
		}
	}
	for (i = 0; i < 82; i++)
		monster[i].y -= allnum.v2;
	for (i = 0; i < 12; i++)
		bigmonster[i].y -= allnum.v2;
	Boss[0].y -= allnum.v2;
	shop_y -= allnum.v2;
	bomb_y -= allnum.v2;
	door_y -= allnum.v2;
}

void get_jewel()   //得到宝石
{
	int i, j;
	int ishave = 0;    //表示是否有空位
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			if (bagposition[i][j] == 0)//空位
				ishave = 1;
	if (xz.y + 95 > h)
	{
		if (brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain >= 1 &&
			brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain <= 5 && ishave == 0)//包满了的提示
		{
			xz.speak_live = 1;
			xz.speak_num = 1;
			return;
		}
		if (brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain >= 1)
		{
			mciSendString(L"close getjewelmusic", 0, 0, 0);
			mciSendString(L"open music\\getjewel.mp3 alias getjewelmusic", 0, 0, 0);
			mciSendString(L"play getjewelmusic", 0, 0, 0);
		}
		if (brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain == 1)
		{
			brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain = 0;
			bag.num3++;
		}
		else if (brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain == 2)
		{
			brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain = 0;
			bag.num4++;
		}
		else if (brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain == 3)
		{
			brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain = 0;
			bag.num5++;
		}
		else if (brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain == 4)
		{
			brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain = 0;
			bag.num6++;
		}
		else if (brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain == 5)
		{
			brick[(xz.y + 47 - h) / 85][(xz.x + 42 - map_num1()) / 85 - map_num()].contain = 0;
			bag.num7++;
		}
	}
}

void man_monster()//小人和怪物碰撞掉血
{
	int i;
	for (i = 0; i < 82; i++)
	{
		if (xz.y + 47 > monster[i].y && xz.y + 47 < monster[i].y + 85 && ((xz.x - 10 < monster[i].x + 75) && (xz.x - 10 > monster[i].x)
			|| (xz.x - 10 + 85 > monster[i].x && xz.x - 10 + 85 < monster[i].x + 75)) && xz.iswudi == 0 && monster[i].blood > 0)
		{
			mciSendString(L"close injuremusic", 0, 0, 0);
			mciSendString(L"open music\\injure.mp3 alias injuremusic", 0, 0, 0);
			mciSendString(L"play injuremusic", 0, 0, 0);
			xz.blood -= 10;
			xz.y -= 50;
			xz.pose = 7;
			xz.iswudi = 1;
			GetLocalTime(&ti);   //获取时间
			allnum.t1 = ti.wSecond;
		}
	}
	for (i = 0; i < 12; i++)
	{
		if (xz.y + 47 > bigmonster[i].y && xz.y + 47 < bigmonster[i].y + 175 && ((xz.x - 10 < bigmonster[i].x + 145) && (xz.x - 10 > bigmonster[i].x)
			|| (xz.x - 10 + 85 > bigmonster[i].x && xz.x - 10 + 85 < bigmonster[i].x + 145)) && xz.iswudi == 0 && bigmonster[i].blood > 0)
		{
			xz.blood -= 30;
			xz.y -= 50;
			xz.pose = 7;
			xz.iswudi = 1;
			GetLocalTime(&ti);   //获取时间
			allnum.t1 = ti.wSecond;
		}
	}
	if (xz.y + 47 > Boss[0].y && xz.y + 47 < Boss[0].y + 405 && ((xz.x - 10 < Boss[0].x + 355) && (xz.x - 10 > Boss[0].x)
		|| (xz.x - 10 + 85 > Boss[0].x && xz.x - 10 + 85 < Boss[0].x + 355)) && xz.iswudi == 0 && Boss[0].blood > 0)
	{
		xz.blood -= 50;
		xz.y -= 50;
		xz.pose = 7;
		xz.iswudi = 1;
		GetLocalTime(&ti);   //获取时间
		allnum.t1 = ti.wSecond;
	}
	if (xz.iswudi == 1)         //两秒后无敌消失
	{
		GetLocalTime(&ti);
		allnum.t2 = ti.wSecond;
		if ((allnum.t1 == 58 || allnum.t1 == 59) && allnum.t2 < 58)
			allnum.t2 += 60;
		if (allnum.t2 - allnum.t1 >= 2)
			xz.iswudi = 0;
	}
}

void oxygen_consume()
{
	if (((xz.y + 95) - h) / 85 > 40 && xz.oxygen - 1 >= 0)
		xz.oxygen--;
	else if (((xz.y + 95) - h) / 85 > 100)
		if (xz.oxygen - 2 >= 0)
			xz.oxygen -= 2;
		else xz.oxygen = 0;
	else if (((xz.y + 95) - h) / 85 > 200 && xz.oxygen - 4 >= 0)
		if (xz.oxygen - 4 >= 0)
			xz.oxygen -= 4;
		else
			xz.oxygen = 0;
	else if (((xz.y + 95) - h) / 85 > 300 && xz.oxygen - 6 >= 0)
		if (xz.oxygen - 6 >= 0)
			xz.oxygen -= 6;
		else
			xz.oxygen = 0;
	if (xz.oxygen == 0)//没氧气人物掉血
		xz.blood--;
	if (((xz.y + 95) - h) / 85 <= 0 && xz.oxygen + 200 <= xz.oxygen_max)
		xz.oxygen += 200;
	else if (((xz.y + 95) - h) / 85 <= 0 && xz.oxygen + 200 > xz.oxygen_max)
		xz.oxygen = xz.oxygen_max;
}

void bag_count()
{
	int i, j;
	int num3 = bag.num3, num4 = bag.num4, num5 = bag.num5, num6 = bag.num6, num7 = bag.num7, num9 = bag.num9;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
		{
			if (num9 > 0)
			{
				bagposition[i][j] = 0;
				num9--;
			}
		}
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 6; j++)
		{
			if (bagposition[i][j] == 0)
			{
				if (num3 >= 10)
				{
					num3 -= 10;
					bagposition[i][j] = 2;
					continue;
				}
				else if (num3 > 0 && num3 < 10)
				{
					num3 = 0;
					bagposition[i][j] = 2;
					continue;
				}
				if (num4 >= 10)
				{
					num4 -= 10;
					bagposition[i][j] = 2;
					continue;
				}
				else if (num4 > 0 && num4 < 10)
				{
					num4 = 0;
					bagposition[i][j] = 2;
					continue;
				}
				if (num5 >= 10)
				{
					num5 -= 10;
					bagposition[i][j] = 2;
					continue;
				}
				else if (num5 > 0 && num5 < 10)
				{
					num5 = 0;
					bagposition[i][j] = 2;
					continue;
				}
				if (num6 >= 10)
				{
					num6 -= 10;
					bagposition[i][j] = 2;
					continue;
				}
				else if (num6 > 0 && num6 < 10)
				{
					num6 = 0;
					bagposition[i][j] = 2;
					continue;
				}
				if (num7 >= 10)
				{
					num7 -= 10;
					bagposition[i][j] = 2;
					continue;
				}
				else if (num7 > 0 && num7 < 10)
				{
					num7 = 0;
					bagposition[i][j] = 2;
					continue;
				}
			}
		}
	}
}

void victory_or_fail()
{	
	if (Boss[0].blood <= 0 && Boss[0].blood > -500)   //音乐只放一次
	{
		mciSendString(L"close vicmusic", 0, 0, 0);
		mciSendString(L"open music\\胜利.mp3 alias vicmusic", 0, 0, 0);
		mciSendString(L"play vicmusic", 0, 0, 0);
	}
	if (Boss[0].blood <= 0)
	{
		Boss[0].blood=-500;   //音乐只放一次
		allnum.show_num = 6;
		putimage(0, 0, &victory_picture);
	}
	if (xz.blood <= 0 && xz.blood > -1000)   //音乐只放一次
	{
		mciSendString(L"close failmusic", 0, 0, 0);
		mciSendString(L"open music\\fail.mp3 alias failmusic", 0, 0, 0);
		mciSendString(L"play failmusic", 0, 0, 0);
	}
	if (xz.blood <= 0)
	{
		xz.blood = -1000;       //音乐只放一次
		allnum.show_num = 6;
		putimage(0, 0, &fail);
		if (GetAsyncKeyState('B') & 0x8000)
		{
			allnum.show_num = 5;
			xz.blood = 160;
			xz.oxygen = 800;
			mciSendString(L"close failmusic", 0, 0, 0);
		}
	}
}

void save_data()   //保存
{
	FILE* fp;
	fopen_s(&fp, "data.txt", " wb");
	if (fp == NULL)
	{
		return;
	}
	fwrite(&h, sizeof(int), 1, fp);
	fwrite(&map_wz, sizeof(int), 1, fp);
	fwrite(&shop_x, sizeof(int), 1, fp);
	fwrite(&shop_y, sizeof(int), 1, fp);
	fwrite(&bomb_x, sizeof(int), 1, fp);
	fwrite(&bomb_y, sizeof(int), 1, fp);
	fwrite(&bomb_live, sizeof(int), 1, fp);
	fwrite(&door_x, sizeof(int), 1, fp);
	fwrite(&door_y, sizeof(int), 1, fp);
	fwrite(&xz, sizeof(Man), 1, fp);
	int i;
	for (i = 0; i < 422; i++)
		fwrite(&brick[i], sizeof(Brick), 64, fp);
	fwrite(&monster, sizeof(Monster), 82, fp);
	fwrite(&bigmonster, sizeof(Monster), 12, fp);
	fwrite(&Boss, sizeof(Monster), 1, fp);
	fwrite(&bag, sizeof(Bag), 1, fp);
	fclose(fp);
}

void read_data()  //继续游戏
{
	FILE* fp;
	fopen_s(&fp, "data.txt", "rb");
	if (fp == NULL)
	{
		return;
	}
	fread(&h, sizeof(int), 1, fp);
	fread(&map_wz, sizeof(int), 1, fp);
	fread(&shop_x, sizeof(int), 1, fp);
	fread(&shop_y, sizeof(int), 1, fp);
	fread(&bomb_x, sizeof(int), 1, fp);
	fread(&bomb_y, sizeof(int), 1, fp);
	fread(&bomb_live, sizeof(int), 1, fp);
	fread(&door_x, sizeof(int), 1, fp);
	fread(&door_y, sizeof(int), 1, fp);
	fread(&xz, sizeof(Man), 1, fp);
	int i;
	for (i = 0; i < 422; i++)
		fread(&brick[i], sizeof(Brick), 64, fp);
	fread(&monster, sizeof(Monster), 82, fp);
	fread(&bigmonster, sizeof(Monster), 12, fp);
	fread(&Boss, sizeof(Monster), 1, fp);
	fread(&bag, sizeof(Bag), 1, fp);
	fclose(fp);
}

void startup()
{
	initgraph(WIDTH, HIGH);
	loadimg();
	allnum.show_num = 0;
	h = 450;
	map_wz = -2500;
	shop_x = 100;
	shop_y = h - 410;
	brick_xy();
	monster_xy(0,0);
	xz.pose = 0;
	xz.blood = 160;
	xz.oxygen = 800;
	xz.blood_max = 160;
	xz.oxygen_max = 800;
	xz.x = 700;
	bag.num9 = 3;
	int i, j, num9 = bag.num9;//给格子赋初值
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
		{
			if (num9 > 0)
			{
				bagposition[i][j] = 0;
				num9--;
			}
			else
				bagposition[i][j] = 1;
		}
	bag.money = 1000000;
	door_x = 2702 + map_wz, door_y = 400 * 85 - 210 + h;
	mciSendString(L"open music\\bk.mp3 alias bkmusic", 0, 0, 0);
	mciSendString(L"play bkmusic repeat", 0, 0, 0);
	xz.num1=5;
	BeginBatchDraw();
}

void show()  //挖矿场景
{
	void show1();
	if (allnum.show_num >= 0 && allnum.show_num <= 4)//开始的场景
	{
		show1();
		return;
	}
	putimage(0, 0, &bk);
	brick_show(brick);
	shop_show();
	door_show();
	speak_show();
	data_show();
	shortmap_show();
	if (xz.iswudi != 1)
		man_show();
	else if (xz.iswudi == 1 && (n % 3 == 0 || n % 3 == 1))
		man_show();
	bomb_show();
	monster_show();
}

void show1()       //开场选择
{
	if (allnum.show_num == 0)
	{
		if (n % 10 >= 0 && n % 10 < 5)
			putimage(0, 0, &cover);
		else if (n % 10 >= 5 && n % 10 <= 9)
			putimage(0, 0, &cover1);
		if (_kbhit())
		{
			allnum.show_num = 1;
		}
		while (MouseHit())
		{
			MOUSEMSG msg;
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
				allnum.show_num = 1;
		}
	}
	else if (allnum.show_num == 1)
	{
		putimage(0, 0, &choose);
		static int zz = 0;
		if (zz == 1)
		{
			putimage(480, 253, &frame_z, SRCAND);
			putimage(480, 253, &frame, SRCPAINT);
		}
		else if (zz == 2)
		{
			putimage(480, 357, &frame_z, SRCAND);
			putimage(480, 357, &frame, SRCPAINT);
		}
		else if (zz == 3)
		{
			putimage(480, 470, &frame_z, SRCAND);
			putimage(480, 470, &frame, SRCPAINT);
		}
		if (allnum.isstatement == 1)
			putimage(170, 20, &statement);
		while (MouseHit())
		{
			MOUSEMSG msg;
			msg = GetMouseMsg();
			if (msg.y > 263 && msg.y < 333 && msg.x>488 && msg.x < 754)
				zz = 1;
			else if (msg.y > 364 && msg.y < 436 && msg.x>488 && msg.x < 754)
				zz = 2;
			else if (msg.y > 475 && msg.y < 550 && msg.x>488 && msg.x < 754)
				zz = 3;
			else
				zz = 0;
			if (WM_LBUTTONDOWN == msg.uMsg)
			{
				if (msg.y > 263 && msg.y < 333 && msg.x>488 && msg.x < 754)
				{
					allnum.show_num = 2;
				}
				else if (msg.y > 475 && msg.y < 550 && msg.x>488 && msg.x < 754)
				{
					allnum.isstatement = 1;
				}
				else if (msg.y > 336 && msg.y < 442 && msg.x>488 && msg.x < 754)
				{
					read_data();
					allnum.show_num = 5;
				}
				if (!(msg.y > 475 && msg.y < 550 && msg.x>488 && msg.x < 754))
					allnum.isstatement = 0;
			}
		}
	}
	else if (allnum.show_num == 2)
	{
		putimage(0, 0, &story);
		while (MouseHit())
		{
			MOUSEMSG msg;
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
				allnum.show_num = 3;
		}
	}
	else if (allnum.show_num == 3)
	{
		putimage(0, 0, &story1);
		while (MouseHit())
		{
			MOUSEMSG msg;
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
				allnum.show_num = 4;
		}
	}
	else if (allnum.show_num == 4)
	{
		putimage(0, 0, &story2);
		while (MouseHit())
		{
			MOUSEMSG msg;
			msg = GetMouseMsg();
			if (WM_LBUTTONDOWN == msg.uMsg)
				allnum.show_num = 5;
		}
	}
}

void input_with()
{
	if (GetAsyncKeyState(VK_RIGHT) & 0x8000 && !(GetAsyncKeyState(VK_DOWN) & 0x8000))
	{
		if (xz.x + 65 < get_wr())
		{
			if (xz.x < 800)
				xz.x += 5+xz.num1;
			else
				map_leftchange();
			xz.pose = 1;
		}
		else
		{
			if (xz.y + 95 - get_h() == h && !(GetAsyncKeyState(VK_UP) & 0x8000))
				right_dig();
		}
	}
	if (GetAsyncKeyState(VK_LEFT) & 0x8000 && !(GetAsyncKeyState(VK_DOWN) & 0x8000))
	{
		if (xz.x + 15 > get_wl())
		{
			if (xz.x > 200)
				xz.x -= 5 + xz.num1;
			else
				map_rightchange();
			xz.pose = 2;
		}
		else
		{
			if (xz.y + 95 - get_h() == h && !(GetAsyncKeyState(VK_UP) & 0x8000))
				left_dig();
		}
	}
	if (GetAsyncKeyState(VK_UP) & 0x8000)
	{
		fly();
	}
	else
		allnum.is_only_one = 0;
	if (GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if (xz.y + 95 == get_h() + h)
		{
			down_dig();
		}
		else
			xz.pose = 0;
	}
	if (GetAsyncKeyState('D') & 0x8000 && bomb_live == 0 && bag.num2 > 0 && xz.y + 95 == h + get_h())
	{
		bomb_live = 1;
		for (int i = 0; i < 82; i++)
			monster[i].ishurt = 0;
		for (int i = 0; i < 12; i++)
			bigmonster[i].ishurt = 0;
		Boss[0].ishurt = 0;
		bomb_x = xz.x + 10;
		bomb_y = xz.y + 30;
	}
	if (GetAsyncKeyState('S') & 0x8000 && bag.num1 > 0 && xz.oxygen < xz.oxygen_max)
	{
		bag.num1--;
		if (xz.oxygen + 500 <= xz.oxygen_max)
			xz.oxygen += 500;
		else
			xz.oxygen = xz.oxygen_max;
	}
	if (GetAsyncKeyState('A') & 0x8000 && bag.num > 0 && xz.blood < xz.blood_max)
	{
		bag.num--;
		if (xz.blood + 100 <= xz.blood_max)
			xz.blood += 100;
		else
			xz.blood = xz.blood_max;
	}
	if (GetAsyncKeyState('Q') & 0x8000)
	{
		data1_show();
		bag_show();
	}
	if (GetAsyncKeyState('E') & 0x8000)
	{
		allnum.isgetshop = 0;
	}
	if (GetAsyncKeyState(VK_LBUTTON) & 0x8000 && allnum.isgetshop == 10)
	{
		control_mouse();
	}
	if (!(GetAsyncKeyState(VK_RIGHT) & 0x8000) && !(GetAsyncKeyState(VK_LEFT) & 0x8000)
		&& !(GetAsyncKeyState(VK_UP) & 0x8000) && !(GetAsyncKeyState(VK_DOWN) & 0x8000))
		xz.pose = 0;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000 && GetAsyncKeyState(VK_DOWN) & 0x8000)
	{
		if (xz.y + 95 == get_h() + h)
		{
			down_dig();
		}
		else
			xz.pose = 0;
	}
}

void input_without()
{
	n++;
	fall();
	monster_fall(monster, 82, 80, 75);
	monster_move(monster, 82, 80, 75);
	monster_fall(bigmonster, 12, 165, 185);
	monster_move(bigmonster, 12, 175, 185);
	monster_move(Boss, 1, 390, 355);
	monster_fall(Boss, 1, 390, 355);
	get_jewel();
	crow_brick();
	/*TCHAR s[10];
	_stprintf_s(s, L"%d", bag.num3);//将整形a转换成字符串
	setbkmode(TRANSPARENT);//字体背景设为透明
	setcolor(BLACK);//字体为黑色
	outtextxy(10, 10, s);//将字符串输出到界面上*/
	if (allnum.isgetshop == 10)      //是否张开商店
	{
		putimage(WIDTH - 583, 0, &shop5);

	}
	if (xz.y + 95 == h && (xz.x + 42 - map_num1()) / 85 - map_num() > 30 && (xz.x + 42 - map_num1()) / 85 - map_num() < 36 && allnum.isgetshop < 10)
		allnum.isgetshop++;
	else if (!((xz.x + 42 - map_num1()) / 85 - map_num() > 30 && (xz.x + 42 - map_num1()) / 85 - map_num() < 36) && allnum.isgetshop > 0)
		allnum.isgetshop--;
	monster_kill();
	man_monster();
	getin_bossroom();
	oxygen_consume();
	bag_count();
	victory_or_fail();
	FlushBatchDraw();
	Sleep(60);
}

int main()
{
	startup();
	while (1)
	{
		show();
		if (allnum.show_num == 5)//游戏进行的场景 只有游戏进行才有输入
			input_with();
		input_without();
	}
	EndBatchDraw();
	_getch();
	closegraph();
	return 0;
}