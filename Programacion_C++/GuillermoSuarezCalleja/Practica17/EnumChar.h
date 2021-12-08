#pragma once

#include <string>
#include <tuple>
#include <cassert>

#define DECLARE_ENUM_VALUE(_ENUM) _ENUM,

#define ENUM_TO_STRING(_ENUM) \
if (_eEnum == Enum::_ENUM) \
{ \
	return #_ENUM; \
}

#define STRING_TO_ENUM(_STRING) \
if (strcmp(_sString, #_STRING) == 0) \
{ \
	return Enum::_STRING; \
}

#define DECLARE_ENUM(_NAME, _LIST) \
struct S##_NAME \
{ \
	enum Enum \
	{ \
		Invalid = -1, \
		_LIST(DECLARE_ENUM_VALUE) \
		Count \
	}; \
	static const char* AsStr(Enum _eEnum) \
	{ \
		_LIST(ENUM_TO_STRING) \
		assert(false); \
		return "Invalid"; \
	} \
	static Enum AsEnum(const char* _sString) \
	{ \
		_LIST(STRING_TO_ENUM) \
		assert(false); \
		return Enum::Invalid; \
	} \
}

#define STATE_ENUM_DEFINITION_LIST(_CALL) \
	_CALL(Idle) \
	_CALL(Chase) \
	_CALL(Attacking) \
	_CALL(Cover) \
  _CALL(Jumping) \
	_CALL(Running)

DECLARE_ENUM(State, STATE_ENUM_DEFINITION_LIST);