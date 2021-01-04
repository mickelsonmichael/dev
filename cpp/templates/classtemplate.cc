class Mather
{
	public:
		Mather() = default;
		~Mather() = default;

		template <class T>
		T Add(T a, T b)
		{
			return a + b;
		}
};

int main()
{

	Mather m;

	m.Add(1, 5);

	return 0;
}

