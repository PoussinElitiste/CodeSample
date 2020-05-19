#ifndef STATIC_ASSERT_H
#define STATIC_ASSERT_H

template<bool>
	struct static_assert;

template<>
	struct static_assert<true>
	{};

#endif
