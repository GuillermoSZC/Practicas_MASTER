#include"SoundFuncts.h"
#include<Windows.h>

bool LaserSound()
{
	return PlaySound(TEXT("laser.wav"), NULL, SND_FILENAME | SND_ASYNC);
} // SND_ASYNC so that the game is not stopped every time when the function is called

bool GameOverSound()
{
	return PlaySound(TEXT("GameOver.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

bool YouWinSound()
{
	return PlaySound(TEXT("YouWin.wav"), NULL, SND_FILENAME | SND_ASYNC);
}