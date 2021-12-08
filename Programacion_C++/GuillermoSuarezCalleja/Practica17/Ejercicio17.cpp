#include <iostream>
#include "EnumChar.h"

int main()
{
	SState::Enum eEnum = SState::AsEnum("Chase");

	printf("%s\n", SState::AsStr(SState::Idle));
	printf("%s\n", SState::AsStr(SState::Chase));
	printf("%s\n", SState::AsStr(SState::Attacking));
	printf("%s\n", SState::AsStr(SState::Cover));
	printf("%s\n", SState::AsStr(SState::Jumping));
	printf("%s\n", SState::AsStr(SState::Running));

	return 0;
}