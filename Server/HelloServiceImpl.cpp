#include "HelloServiceImpl.h"

::grpc::Status HelloServiceImpl::Hi(::grpc::ServerContext* context, const::HelloRequest* request, ::HelloResponse* response)
{
	std::cout << "Hello " << request->name() << std::endl;
	return ::grpc::Status::OK;
}
