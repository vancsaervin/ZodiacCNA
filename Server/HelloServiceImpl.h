#pragma once
#include <HelloOperation.grpc.pb.h>

class HelloServiceImpl final : public HelloService::Service
{
public:
	HelloServiceImpl() {};
	::grpc::Status Hi(::grpc::ServerContext* context, const ::HelloRequest* request, ::HelloResponse* response) override;

};

