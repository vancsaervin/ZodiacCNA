// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: HelloOperation.proto

#include "HelloOperation.pb.h"
#include "HelloOperation.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>

static const char* HelloService_method_names[] = {
  "/HelloService/Hi",
};

std::unique_ptr< HelloService::Stub> HelloService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< HelloService::Stub> stub(new HelloService::Stub(channel));
  return stub;
}

HelloService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Hi_(HelloService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status HelloService::Stub::Hi(::grpc::ClientContext* context, const ::HelloRequest& request, ::HelloResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Hi_, context, request, response);
}

void HelloService::Stub::experimental_async::Hi(::grpc::ClientContext* context, const ::HelloRequest* request, ::HelloResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Hi_, context, request, response, std::move(f));
}

void HelloService::Stub::experimental_async::Hi(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::HelloResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc_impl::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Hi_, context, request, response, std::move(f));
}

void HelloService::Stub::experimental_async::Hi(::grpc::ClientContext* context, const ::HelloRequest* request, ::HelloResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Hi_, context, request, response, reactor);
}

void HelloService::Stub::experimental_async::Hi(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::HelloResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc_impl::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Hi_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::HelloResponse>* HelloService::Stub::AsyncHiRaw(::grpc::ClientContext* context, const ::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::HelloResponse>::Create(channel_.get(), cq, rpcmethod_Hi_, context, request, true);
}

::grpc::ClientAsyncResponseReader< ::HelloResponse>* HelloService::Stub::PrepareAsyncHiRaw(::grpc::ClientContext* context, const ::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc_impl::internal::ClientAsyncResponseReaderFactory< ::HelloResponse>::Create(channel_.get(), cq, rpcmethod_Hi_, context, request, false);
}

HelloService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HelloService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HelloService::Service, ::HelloRequest, ::HelloResponse>(
          std::mem_fn(&HelloService::Service::Hi), this)));
}

HelloService::Service::~Service() {
}

::grpc::Status HelloService::Service::Hi(::grpc::ServerContext* context, const ::HelloRequest* request, ::HelloResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

