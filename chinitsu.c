#include<stdio.h>
#include<string.h>

/*********************************************************/
/*    object name: chinitsu.c                            */
/*                                                       */
/*    object explane: �s���Y���疳���ׂ�13�v�I����       */
/*    �Ƃ��ɒ��v���Ă����m�������߂�                     */
/*                                                       */
/*********************************************************/

char chk_valid_tehai( char *tehai );
char chk_tenpai( char *tehai );

/*********************************************************/
/*    function name: main( void )                        */
/*                                                       */
/*    function explane: ���̃I�u�W�F�N�g�̃��C������     */
/*                                                       */
/*    function parameter: �Ȃ�                           */
/*                                                       */
/*    return value :�Ȃ�                                 */
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
	unsigned int valid_tehai_cnt;   /* ���v��13���̃p�^�[�����J�E���g */
	unsigned int tenpai_tehai_cnt;  /* ���v�����v�̃p�^�[�����J�E���g */
	char tehai[11]; /* 1������9���̂��ꂼ���̖������i�[ */ /* [9][10]�͏���0�̃_�~�[ */
	int i;
	
	valid_tehai_cnt = 0;
	tenpai_tehai_cnt = 0;
	
	for( i = 0; i < 11; i++ )
	{
		tehai[i] = 0;
	}
	/* 1������9���܂ŁA���ꂼ��0������4���̍��v5�p�^�[�����ԗ� */
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
										if( chk_valid_tehai( tehai ) == 1 ) /*���v��13���̂Ƃ� */
										{
											valid_tehai_cnt++;
											if( chk_tenpai( tehai ) == 1 ) /* ���v�����v�̂Ƃ� */
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
	
	printf("�m���� %d / %d \n %f �p�[�Z���g�ł��B" , tenpai_tehai_cnt, valid_tehai_cnt, (float)tenpai_tehai_cnt / (float)valid_tehai_cnt * 100 );
}

/*********************************************************/
/*    function name: chk_valid_tehai( char *tehai )      */
/*                                                       */
/*    function explane: ���v��13���ł��邱�Ƃ̊m�F       */
/*                                                       */
/*    function parameter: ���v�|�C���^                   */
/*                                                       */
/*    return value :�^ = 1 �U = 0                        */
/*                                                       */
/*********************************************************/
char chk_valid_tehai( char *tehai )
{
	int i;
	int tehai_total;
	char retval;
	
	tehai_total = 0;
	retval = 0;
	
	/* ���v�̖������Z�o */
	for( i = 0; i < 9; i++)
	{
		tehai_total += tehai[i];
	}
	
	/* 13���Ȃ�true */
	if( tehai_total == 13 )
	{
		retval = 1;
	}
	
	return ( retval );
}
/*********************************************************/
/*    function name: chk_tenpai( char *tehai )           */
/*                                                       */
/*    function explane: ���v�����v���Ă��邱�Ƃ̊m�F     */
/*                                                       */
/*    function parameter: ���v�|�C���^                   */
/*                                                       */
/*    return value :�^ = 1 �U = 0                        */
/*                                                       */
/*********************************************************/
char chk_tenpai( char *tehai )
{
	char tehai_temp[11];
	int jantou_index;
	int tehai_index;
	int ukihai_high; /* �����v�i�傫���ق��j*/
	int ukihai_low;  /* �����v�i�������ق��j*/
	int i;

	jantou_index = 0;
	
	/* ���������钮�v�`�̔��� */
	while( jantou_index < 9 )
	{
		for( i = 0; i < 11; i++)
		{
			tehai_temp[i] = tehai[i];
		}
		
		/* 2���ȏ㎝���Ă��Ȃ������玟�̔v���Q�� */
		if( tehai_temp[jantou_index] < 2 )
		{
			jantou_index++;
			continue;
		}
		/* 2���ȏ㎝���Ă����琝�����擾 */
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
			/* �Q�Ƃ��Ă����v��3���ȏ゠���Ƃ��A���q���擾 */
			if( tehai_temp[tehai_index] >= 3 )
			{
				tehai_temp[tehai_index] -= 3;
				continue;
			}
			/* �Q�Ƃ��Ă����v��2�������Ƃ��̏��� */
			else if( tehai_temp[tehai_index] == 2 )
			{
				/* ���q���擾�ł����Ƃ��A���q���擾 */
				if( tehai_temp[tehai_index + 1] >= 1 && tehai_temp[tehai_index + 2] >= 1)
				{
					tehai_temp[tehai_index] -= 1;
					tehai_temp[tehai_index+1] -= 1;
					tehai_temp[tehai_index+2] -= 1;
					continue;
				}
				/* ���q���擾�ł����A�܂������v���o�^�����Ă��Ȃ����΁A�Ύq�𕂂��v�ɓo�^ */
				else if( ukihai_low == 0 && ukihai_high == 0 )
				{
					ukihai_low = tehai_index + 1;
					ukihai_high = tehai_index + 1;
					tehai_temp[tehai_index] -= 2;
					tehai_index++;
					continue;
				}
				/* ���q���擾�ł����A�����v���o�^�ς݂̂Ƃ��A���v�`�łȂ� */
				else
				{
					break;
				}
			}
			/* �Q�Ƃ��Ă����v��1�������Ƃ��̏��� */
			else if( tehai_temp[tehai_index] == 1 )
			{
				/* ���q���擾�ł����Ƃ��A���q���擾 */
				if( tehai_temp[tehai_index + 1] > 0 && tehai_temp[tehai_index + 2] > 0)
				{
					tehai_temp[tehai_index] -= 1;
					tehai_temp[tehai_index + 1 ] -= 1;
					tehai_temp[tehai_index + 2 ] -= 1;
					tehai_index++;
					continue;
				}
				/* ���q���擾�ł����A�܂������v��1�����o�^�����Ă��Ȃ��Ƃ��A�Q�Ƃ��Ă����v�𕂂��v(��)�ɓo�^ */
				else if( ukihai_low == 0 )
				{
					ukihai_low = tehai_index + 1;
					tehai_temp[tehai_index] -= 1;
					tehai_index++;
					continue;
				}
				/* ���q���擾�ł����A�����v��1�������o�^�����Ă��Ȃ��Ƃ��A�Q�Ƃ��Ă����v�𕂂��v(��)�ɓo�^ */
				else if( ukihai_high == 0 )
				{
					ukihai_high = tehai_index + 1;
					tehai_temp[tehai_index] -= 1;
					tehai_index++;
					continue;
				}
				/* ���q���擾�ł����A�����v��2���o�^�ς݂̂Ƃ��A���v�`�łȂ� */
				else
				{
					break;
				}
			}
			/* �Q�Ƃ��Ă����v��1�����Ȃ��Ƃ��A���̔v���Q�� */
			else
			{
				tehai_index++;
				continue;
			}
		}
		/* �Ō��̔v�܂Ń`�F�b�N�����Ƃ��̏��� */
		if ( tehai_index == 9 )
		{
			/* �����v���҂��`(11�Ƃ�12�Ƃ�13�̂悤�ɁA2�̕����v�̍���0����2�̂Ƃ�)�ɂȂ��Ă����Ƃ��A���v */
			if( ukihai_high - ukihai_low < 3 )
			{
				return 1;
			}
			/* �����v���҂��`�łȂ�(14�Ƃ�58�Ƃ�19�Ƃ�)�Ƃ��A���v�łȂ� */
			else
			{
				continue;
			}
		}
		/* �r���Ń��[�v�𔲂����Ƃ��A���v�łȂ� */
		else
		{
			continue;
		}
	}
	/* �������Ȃ����v�`(�P�R�҂�)�̔��� */
	tehai_index = 0;
	ukihai_high = 0;
	ukihai_low = 0;
	
	for( i = 0; i < 11; i++)
	{
		tehai_temp[i] = tehai[i];
	}
	
	
	while( tehai_index < 9 )
	{
		/* �Q�Ƃ��Ă����v��3���ȏ゠���Ƃ��A���q���擾 */
		if( tehai_temp[tehai_index] >= 3 )
		{
			tehai_temp[tehai_index] -= 3;
			continue;
		}
		/* �Q�Ƃ��Ă����v��2�������Ƃ��̏��� */
		else if( tehai_temp[tehai_index] = 2 )
		{
			/* ���q���擾�ł����Ƃ��A���q���擾 */
			if( tehai_temp[tehai_index + 1] >= 1 && tehai_temp[tehai_index + 2] >= 1 )
			{
				tehai_temp[tehai_index] -= 1;
				tehai_temp[tehai_index+1] -= 1;
				tehai_temp[tehai_index+2] -= 1;
				continue;
			}
			/* ���q���擾�ł��Ȃ��Ƃ��A���v�łȂ� */
			else
			{
				break;
			}
		}
		/* �Q�Ƃ��Ă����v��1�������Ƃ��̏��� */
		else if( tehai_temp[tehai_index] == 1 )
		{
			/* ���q���擾�ł����Ƃ��A���q���擾 */
			if( tehai_temp[tehai_index + 1] > 0 && tehai_temp[tehai_index + 2] > 0)
			{
				tehai_temp[tehai_index] -= 1;
				tehai_temp[tehai_index + 1 ] -= 1;
				tehai_temp[tehai_index + 2 ] -= 1;
				tehai_index++;
				continue;
			}
			/* ���q���擾�ł����A�܂������v���o�^�����Ă��Ȃ����΁A�Q�Ƃ��Ă����v�𕂂��v�ɓo�^ */
			else if( ukihai_low == 0 )
			{
				ukihai_low = tehai_index + 1;
				tehai_temp[tehai_index] -= 1;
				tehai_index++;
				continue;
			}
			/* ���q���擾�ł����A���ɕ����v���o�^�����Ă����Ƃ��A���v�łȂ� */
			else
			{
				break;
			}
		}
		/* �Q�Ƃ��Ă����v��1�����Ȃ��Ƃ��A���̔v���Q�� */
		else
		{
			tehai_index++;
			continue;
		}
	}
	/* �Ō��̔v�܂Ń`�F�b�N�ł����Ƃ��A���v */
	if ( tehai_index == 9 )
	{
		return 1;
	}
	/* �r���Ń��[�v�𔲂����Ƃ��A���v�łȂ� */
	return 0;
}
