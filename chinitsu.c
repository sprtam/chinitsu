#include<stdio.h>
#include<string.h>

/*********************************************************/
/*    object name: chinitsu.c                            */
/*                                                       */
/*    object explane: ピンズから無作為に13牌選んだ       */
/*    ときに聴牌している確率を求める                     */
/*                                                       */
/*********************************************************/

char chk_valid_tehai( char *tehai );
char chk_tenpai( char *tehai );

/*********************************************************/
/*    function name: main( void )                        */
/*                                                       */
/*    function explane: このオブジェクトのメイン処理     */
/*                                                       */
/*    function parameter: なし                           */
/*                                                       */
/*    return value :なし                                 */
/*                                                       */
/*********************************************************/

void main( void )
{
	char loopnum_of_pin_one;
	char loopnum_of_pin_two;
	char loopnum_of_pin_three;
	char loopnum_of_pin_four;
	char loopnum_of_pin_five;
	char loopnum_of_pin_six;
	char loopnum_of_pin_seven;
	char loopnum_of_pin_eight;
	char loopnum_of_pin_nine;
	unsigned int valid_tehai_cnt;   /* 手牌が13枚のパターンをカウント */
	unsigned int tenpai_tehai_cnt;  /* 手牌が聴牌のパターンをカウント */
	char tehai[11]; /* 1筒から9筒のそれぞれの枚数を格納 */ /* [9][10]は常に0のダミー */
	int i;
	
	valid_tehai_cnt = 0;
	tenpai_tehai_cnt = 0;
	
	for( i = 0; i < 11; i++ )
	{
		tehai[i] = 0;
	}
	/* 1筒から9筒まで、それぞれ0枚から4枚の合計5パターンを網羅 */
	for( loopnum_of_pin_one = 0; loopnum_of_pin_one < 5; loopnum_of_pin_one++)
	{
		tehai[0] = loopnum_of_pin_one;
		for( loopnum_of_pin_two = 0; loopnum_of_pin_two < 5; loopnum_of_pin_two++)
		{
			tehai[1] = loopnum_of_pin_two;
			for( loopnum_of_pin_three = 0; loopnum_of_pin_three < 5; loopnum_of_pin_three++)
			{
				tehai[2] = loopnum_of_pin_three;
				for( loopnum_of_pin_four = 0; loopnum_of_pin_four < 5; loopnum_of_pin_four++)
				{
					tehai[3] = loopnum_of_pin_four;
					for( loopnum_of_pin_five = 0; loopnum_of_pin_five < 5; loopnum_of_pin_five++)
					{
						tehai[4] = loopnum_of_pin_five;
						for( loopnum_of_pin_six = 0; loopnum_of_pin_six < 5; loopnum_of_pin_six++)
						{
							tehai[5] = loopnum_of_pin_six;
							for( loopnum_of_pin_seven = 0; loopnum_of_pin_seven < 5; loopnum_of_pin_seven++)
							{
								tehai[6] = loopnum_of_pin_seven;
								for( loopnum_of_pin_eight = 0; loopnum_of_pin_eight < 5; loopnum_of_pin_eight++)
								{
									tehai[7] = loopnum_of_pin_eight;
									for( loopnum_of_pin_nine = 0; loopnum_of_pin_nine < 5; loopnum_of_pin_nine++)
									{
										tehai[8] = loopnum_of_pin_nine;
										if( chk_valid_tehai( tehai ) == 1 ) /*手牌が13枚のとき */
										{
											valid_tehai_cnt++;
											if( chk_tenpai( tehai ) == 1 ) /* 手牌が聴牌のとき */
											{
												tenpai_tehai_cnt++;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	printf("確率は %d / %d \n %f パーセントです。" , tenpai_tehai_cnt, valid_tehai_cnt, (float)tenpai_tehai_cnt / (float)valid_tehai_cnt * 100 );
}

/*********************************************************/
/*    function name: chk_valid_tehai( char *tehai )      */
/*                                                       */
/*    function explane: 手牌が13枚であることの確認       */
/*                                                       */
/*    function parameter: 手牌ポインタ                   */
/*                                                       */
/*    return value :真 = 1 偽 = 0                        */
/*                                                       */
/*********************************************************/
char chk_valid_tehai( char *tehai )
{
	int i;
	int tehai_total;
	char retval;
	
	tehai_total = 0;
	retval = 0;
	
	/* 手牌の枚数を算出 */
	for( i = 0; i < 9; i++)
	{
		tehai_total += tehai[i];
	}
	
	/* 13枚ならtrue */
	if( tehai_total == 13 )
	{
		retval = 1;
	}
	
	return ( retval );
}
/*********************************************************/
/*    function name: chk_tenpai( char *tehai )           */
/*                                                       */
/*    function explane: 手牌が聴牌していることの確認     */
/*                                                       */
/*    function parameter: 手牌ポインタ                   */
/*                                                       */
/*    return value :真 = 1 偽 = 0                        */
/*                                                       */
/*********************************************************/
char chk_tenpai( char *tehai )
{
	char tehai_temp[11];
	int jantou_index;
	int tehai_index;
	int ukihai_high; /* 浮き牌（大きいほう）*/
	int ukihai_low;  /* 浮き牌（小さいほう）*/
	int i;
	int toitsu_cnt; /* チートイ判断の際に使用 */

	jantou_index = 0;
	
	/* 雀頭がある聴牌形の判定 */
	while( jantou_index < 9 )
	{
		for( i = 0; i < 11; i++)
		{
			tehai_temp[i] = tehai[i];
		}
		
		/* 2枚以上持っていなかったら次の牌を参照 */
		if( tehai_temp[jantou_index] < 2 )
		{
			jantou_index++;
			continue;
		}
		/* 2枚以上持っていたら雀頭を取得 */
		else
		{
			tehai_temp[jantou_index] -= 2;
			tehai_index = 0;
			jantou_index++;
		}
		
		tehai_index = 0;
		ukihai_high = 0;
		ukihai_low = 0;
		
		while( tehai_index < 9 )
		{
			/* 参照している牌が3枚以上あるとき、刻子を取得 */
			if( tehai_temp[tehai_index] >= 3 )
			{
				tehai_temp[tehai_index] -= 3;
				continue;
			}
			/* 参照している牌が2枚あるときの処理 */
			else if( tehai_temp[tehai_index] == 2 )
			{
				/* 順子が取得できるとき、順子を取得 */
				if( tehai_temp[tehai_index + 1] >= 1 && tehai_temp[tehai_index + 2] >= 1)
				{
					tehai_temp[tehai_index] -= 1;
					tehai_temp[tehai_index+1] -= 1;
					tehai_temp[tehai_index+2] -= 1;
					continue;
				}
				/* 順子が取得できず、まだ浮き牌が登録されていなければ、対子を浮き牌に登録 */
				else if( ukihai_low == 0 && ukihai_high == 0 )
				{
					ukihai_low = tehai_index + 1;
					ukihai_high = tehai_index + 1;
					tehai_temp[tehai_index] -= 2;
					tehai_index++;
					continue;
				}
				/* 順子が取得できず、浮き牌が登録済みのとき、聴牌形でない */
				else
				{
					break;
				}
			}
			/* 参照している牌が1枚あるときの処理 */
			else if( tehai_temp[tehai_index] == 1 )
			{
				/* 順子が取得できるとき、順子を取得 */
				if( tehai_temp[tehai_index + 1] > 0 && tehai_temp[tehai_index + 2] > 0)
				{
					tehai_temp[tehai_index] -= 1;
					tehai_temp[tehai_index + 1 ] -= 1;
					tehai_temp[tehai_index + 2 ] -= 1;
					tehai_index++;
					continue;
				}
				/* 順子が取得できず、まだ浮き牌が1枚も登録されていないとき、参照している牌を浮き牌(小)に登録 */
				else if( ukihai_low == 0 )
				{
					ukihai_low = tehai_index + 1;
					tehai_temp[tehai_index] -= 1;
					tehai_index++;
					continue;
				}
				/* 順子が取得できず、浮き牌が1枚しか登録されていないとき、参照している牌を浮き牌(大)に登録 */
				else if( ukihai_high == 0 )
				{
					ukihai_high = tehai_index + 1;
					tehai_temp[tehai_index] -= 1;
					tehai_index++;
					continue;
				}
				/* 順子が取得できず、浮き牌が2枚登録済みのとき、聴牌形でない */
				else
				{
					break;
				}
			}
			/* 参照している牌が1枚もないとき、次の牌を参照 */
			else
			{
				tehai_index++;
				continue;
			}
		}
		/* 最後の牌までチェックしたときの処理 */
		if ( tehai_index == 9 )
		{
			/* 浮き牌が待ち形(11とか12とか13のように、2つの浮き牌の差が0から2のとき)になっているとき、聴牌 */
			if( ukihai_high - ukihai_low < 3 )
			{
				return 1;
			}
			/* 浮き牌が待ち形でない(14とか58とか19とか)とき、聴牌でない */
			else
			{
				continue;
			}
		}
		/* 途中でループを抜けたとき、聴牌でない */
		else
		{
			continue;
		}
	}
	/* 雀頭がない聴牌形(単騎待ち)の判定 */
	tehai_index = 0;
	ukihai_high = 0;
	ukihai_low = 0;
	
	for( i = 0; i < 11; i++)
	{
		tehai_temp[i] = tehai[i];
	}
	
	
	while( tehai_index < 9 )
	{
		/* 参照している牌が3枚以上あるとき、刻子を取得 */
		if( tehai_temp[tehai_index] >= 3 )
		{
			tehai_temp[tehai_index] -= 3;
			continue;
		}
		/* 参照している牌が2枚あるときの処理 */
		else if( tehai_temp[tehai_index] = 2 )
		{
			/* 順子が取得できるとき、順子を取得 */
			if( tehai_temp[tehai_index + 1] >= 1 && tehai_temp[tehai_index + 2] >= 1 )
			{
				tehai_temp[tehai_index] -= 1;
				tehai_temp[tehai_index+1] -= 1;
				tehai_temp[tehai_index+2] -= 1;
				continue;
			}
			/* 順子が取得できないとき、聴牌でない */
			else
			{
				break;
			}
		}
		/* 参照している牌が1枚あるときの処理 */
		else if( tehai_temp[tehai_index] == 1 )
		{
			/* 順子が取得できるとき、順子を取得 */
			if( tehai_temp[tehai_index + 1] > 0 && tehai_temp[tehai_index + 2] > 0)
			{
				tehai_temp[tehai_index] -= 1;
				tehai_temp[tehai_index + 1 ] -= 1;
				tehai_temp[tehai_index + 2 ] -= 1;
				tehai_index++;
				continue;
			}
			/* 順子が取得できず、まだ浮き牌が登録されていなければ、参照している牌を浮き牌に登録 */
			else if( ukihai_low == 0 )
			{
				ukihai_low = tehai_index + 1;
				tehai_temp[tehai_index] -= 1;
				tehai_index++;
				continue;
			}
			/* 順子が取得できず、既に浮き牌が登録されているとき、聴牌でない */
			else
			{
				break;
			}
		}
		/* 参照している牌が1枚もないとき、次の牌を参照 */
		else
		{
			tehai_index++;
			continue;
		}
	}
	/* 最後の牌までチェックできたとき、聴牌 */
	if ( tehai_index == 9 )
	{
		return 1;
	}
	
	/* チートイの判定 */
	tehai_index = 0;
	ukihai_high = 0;
	ukihai_low = 0;
	toitsu_cnt = 0;
	
	for( i = 0; i < 11; i++)
	{
		tehai_temp[i] = tehai[i];
	}
	
	while( toitsu_cnt < 6 )
	{
		if( tehai_temp[tehai_index] == 2 )
		{
			toitsu_cnt++;
			tehai_index++;
			continue;
		}
		else if( tehai_temp[tehai_index] == 0 )
		{
			tehai_index++;
			continue;
		}
		else if( tehai_temp[tehai_index] == 1 )
		{
			if( ukihai_low == 0 )
			{
				ukihai_low = tehai_index + 1;
				tehai_index++;
				continue;
			}
			else
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	
	if( toitsu_cnt == 6 )
	{
		return 1;
	}
	/* 途中でループを抜けたとき、聴牌でない */
	return 0;
}
