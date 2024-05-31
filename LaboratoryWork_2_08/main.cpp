#include "sources.hpp"


int main()
{
	{
		int x, y, z;
		std::cout << "Enter point_1 (x, y, x): ";
		std::cin >> x >> y >> z;
		MyPoint point_1(x, y, z);
		MyUnique<MyPoint> unique_ptr1 = Make_MyUnique<MyPoint>(point_1);

		std::cout << "Address in memory  ( unique_ptr1.get() ): " << unique_ptr1.get() << std::endl;
		std::cout << "Dereferencing the pointer ( *unique_ptr1 ): " << *unique_ptr1 << std::endl;

		std::cout << "=============================================================" << std::endl;

		std::cout << "Enter point_2 (x, y, x): ";
		std::cin >> x >> y >> z;
		MyPoint point_2(x, y, z);
		MyUnique<MyPoint> unique_ptr2 = Make_MyUnique<MyPoint>(point_2);
		std::cout << "(unique_ptr1) address: " << unique_ptr1.get() << " value: " << *unique_ptr1 << std::endl;
		std::cout << "(unique_ptr2) address: " << unique_ptr2.get() << " value: " << *unique_ptr2 << std::endl;
		unique_ptr1 = std::move(unique_ptr2);
		std::cout << "unique_ptr1 = std::move(unique_ptr2):" << std::endl;
		std::cout << "(unique_ptr1) address: " << unique_ptr1.get() << " value: " << *unique_ptr1 << std::endl;
		std::cout << "(unique_ptr2) address: " << unique_ptr2.get() << std::endl;

		std::cout << "=============================================================" << std::endl;

		std::cout << "(unique_ptr1) address: " << unique_ptr1.get() << " value: " << *unique_ptr1 << std::endl;
		MyUnique<MyPoint> unique_ptr3(std::move(unique_ptr1));
		std::cout << "(unique_ptr1) address: " << unique_ptr1.get() << std::endl;
		std::cout << "(unique_ptr3) address: " << unique_ptr3.get() << " value: " << *unique_ptr3 << std::endl;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////////////////

	{
		int x, y, z;
		
		std::cout << "Enter point_1 (x, y, x): ";
		std::cin >> x >> y >> z;
		MyPoint point_1(x, y, z);
		MyShared<MyPoint> shared_ptr1 = Make_MyShared<MyPoint>(point_1);

		std::cout << "Address in memory  ( shared_ptr1.get() ): " << shared_ptr1.get() << std::endl;
		std::cout << "Dereferencing the pointer ( *shared_ptr1 ): " << *shared_ptr1 << std::endl;

		std::cout << "=============================================================" << std::endl;

		std::cout << "Enter point_2 (x, y, x): ";
		std::cin >> x >> y >> z;
		MyPoint point_2(x, y, z);
		MyShared<MyPoint> shared_ptr2 = Make_MyShared<MyPoint>(point_2);
		std::cout << "(shared_ptr1) address: " << shared_ptr1.get() << " value: " << *shared_ptr1 << std::endl;
		std::cout << "(shared_ptr2) address: " << shared_ptr2.get() << " value: " << *shared_ptr2 << std::endl;
		shared_ptr1 = std::move(shared_ptr2);
		std::cout << "shared_ptr1 = std::move(shared_ptr2):" << std::endl;
		std::cout << "(shared_ptr1) address: " << shared_ptr1.get() << " value: " << *shared_ptr1 << std::endl;
		std::cout << "(shared_ptr2) address: " << shared_ptr2.get() << std::endl;

		std::cout << "=============================================================" << std::endl;

		std::cout << "(shared_ptr1) address: " << shared_ptr1.get() << " value: " << *shared_ptr1 << std::endl;
		MyShared<MyPoint> shared_ptr3(std::move(shared_ptr1));
		std::cout << "(shared_ptr1) address: " << shared_ptr1.get() << std::endl;
		std::cout << "(shared_ptr3) address: " << shared_ptr3.get() << " value: " << *shared_ptr3 << std::endl;

		std::cout << "=============================================================" << std::endl;

		std::cout << "Enter point1 (x, y, x): ";
		std::cin >> x >> y >> z;
		MyPoint point1(x, y, z);
		MyShared<MyPoint> shared_ptr1_point = Make_MyShared<MyPoint>(point1);
		std::cout << "(shared_ptr1_point) address: " << shared_ptr1_point.get() << " value: " << *shared_ptr1_point << std::endl;
		MyShared<MyPoint> shared_ptr2_point(shared_ptr1_point);
		std::cout << "(shared_ptr2_point) address: " << shared_ptr2_point.get() << " value: " << *shared_ptr2_point << std::endl;

		std::cout << "=============================================================" << std::endl;
		
		std::cout << "Enter point2 (x, y, x): ";
		std::cin >> x >> y >> z;
		MyPoint point2(x, y, z);
		std::cout << "test";
		MyShared<MyPoint> shared_ptr3_point = Make_MyShared<MyPoint>(point2);
		{
			auto test = shared_ptr3_point;
		}
		std::cout << "(shared_ptr3_point) address: " << shared_ptr3_point.get() << " value: " << *shared_ptr3_point << std::endl;
		shared_ptr2_point = shared_ptr3_point;
		std::cout << "(shared_ptr2_point) address: " << shared_ptr2_point.get() << " value: " << *shared_ptr2_point << std::endl;
	}

	return 0;
}