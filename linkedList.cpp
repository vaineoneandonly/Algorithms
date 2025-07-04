import std;
using namespace std;

template <typename T>
struct llNode
{
	T					   data{};
	shared_ptr<llNode<T>>  next{nullptr};
};

template <typename... T>
struct llNode2
{
	variant<T...> data{};
	shared_ptr<llNode2<T...>>  next{nullptr};
};

int main()
{
	llNode head{ 20 };
	head.next = make_shared<llNode<int>>(25);

	shared_ptr<llNode2<string>> h2{ make_shared<llNode2<string>>("23")};

	weak_ptr<llNode2<string>> p{ h2 };

	auto tsp{ p.lock() };

	visit([](auto &&val) {
		std::cout << val << '\n';
	}, tsp->data);

} 