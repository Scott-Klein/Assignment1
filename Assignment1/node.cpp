//Refactored once
#include "node.h"

bool operator<(const Node& lhs, const Node& rhs)
{
	if (lhs.data->GetHash() == rhs.data->GetHash())
	{
		return false;
	}
	return (lhs.value > rhs.value);
}