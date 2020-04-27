#pragma once
#include <ZodieOperation.grpc.pb.h>
#include <fstream>
#include <vector>

class ZodieServiceImpl final : public ZodieService::Service
{
public:
	struct Zodii {
		std::string monthBegin;
		std::string dayBegin;
		std::string monthEnd;
		std::string dayEnd;
		std::string zodie;
	};
public:
	ZodieServiceImpl() {};
	::grpc::Status Verify(::grpc::ServerContext* context, const ::ZodieRequest* request, ::ZodieResponse* response) override;
};

