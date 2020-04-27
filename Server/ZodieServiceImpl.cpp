#include "ZodieServiceImpl.h"

::grpc::Status ZodieServiceImpl::Verify(::grpc::ServerContext* context, const::ZodieRequest* request, ::ZodieResponse* response)
{
	std::ifstream fin("Zodii.in");

	std::vector<Zodii> date;
	Zodii temp;
	std::string line;

	while (getline(fin, line))
	{
		temp.zodie = line;
		getline(fin, line);
		temp.monthBegin = line.substr(0, 2);
		temp.dayBegin = line.substr(3, 2);
		temp.monthEnd = line.substr(6, 2);
		temp.dayEnd = line.substr(9, 2);

		date.push_back(temp);
	}

	std::string data = request->date();
	std::string month = data.substr(0, 2);
	std::string day = data.substr(3, 2);

	int entry = std::stoi(month) * 100 + std::stoi(day);
	for (auto zodie : date)
	{
		//std::cout << zodie.zodie << " - " << zodie.monthBegin << "/" << zodie.dayBegin << " - " << zodie.monthEnd << "/" << zodie.dayEnd << std::endl;
		int startDate = std::stoi(zodie.monthBegin) * 100 + std::stoi(zodie.dayBegin);
		int endDate = std::stoi(zodie.monthEnd) * 100 + std::stoi(zodie.dayEnd);
		if (entry >= startDate && entry <= endDate)
		{
			std::cout << zodie.zodie << std::endl;
			return ::grpc::Status::OK;
		}
		else if (endDate - startDate < 0)
		{
			std::cout << zodie.zodie << std::endl;
			return ::grpc::Status::OK;
		}
	}

	
}
