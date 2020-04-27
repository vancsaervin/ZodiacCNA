#include <iostream>
#include <sstream>
#include <string>
#include <ZodieOperation.grpc.pb.h>
#include <grpc/grpc.h>
#include <grpcpp/channel.h>
#include <grpcpp/client_context.h>
#include <grpcpp/create_channel.h>
#include <grpcpp/security/credentials.h>

using grpc::Channel;
using grpc::ClientContext;
using grpc::ClientReader;
using grpc::ClientReaderWriter;
using grpc::ClientWriter;

bool isLeap(int year)
{
    return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool Validate(int y, int m, int d)
{
    if (y > 9999 ||
        y < 1800)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;

    if (m == 2)
    {
        if (isLeap(y))
            return (d <= 29);
        else
            return (d <= 28);
    }

    if (m == 4 || m == 6 ||
        m == 9 || m == 11)
        return (d <= 30);

    return true;
}

bool Input(const std::string& date)
{
    std::stringstream ss(date);
    std::string d, mm, y;

    std::getline(ss, mm, '/');
    std::getline(ss, d, '/');
    std::getline(ss, y, '/');


    if (Validate(std::stoi(y), std::stoi(mm), std::stoi(d)))
        return true;

    return false;
}

int main()
{
    /*grpc_init();
    ClientContext context;
    auto hello = HelloService::NewStub(grpc::CreateChannel("localhost:8888", grpc::InsecureChannelCredentials()));
    
    HelloRequest helloRequest;
    std::string name;
    std::cout << "Enter your name: ";
    std::cin >> name;
    helloRequest.set_name(name);
    
    HelloResponse response;
    auto status = hello->Hi(&context, helloRequest, &response);
    */

    grpc_init();
    ClientContext context;
    auto zodie = ZodieService::NewStub(grpc::CreateChannel("localhost:8888", grpc::InsecureChannelCredentials()));

    ZodieRequest zodieRequest;
    
    std::string date;

    bool ok = false;

    do {
        std::cin >> date;

        if (Input(date))
        {
            zodieRequest.set_date(date);
            ok = true;
        }
        else
        {
            std::cout << "[ERROR] : Data format invalid! Try again!" << std::endl;
        }

    } while (ok != true);

    ZodieResponse response;
    auto status = zodie->Verify(&context, zodieRequest, &response);
}