template <typename T, typename O>
bool inline instanceof(const O& object)
{
	return dynamic_cast<const T*>(&object) != nullptr;
}

template <typename T, typename O>
bool inline instanceof(const O* object)
{
	return dynamic_cast<const T*>(object) != nullptr;
}