/*
*Programmer: Layyana Junaid (23k0056)
*Date: 30th March 2024
*Description: developing a cybersecurity framework
*/

#include <iostream>
#include <string>

class SecurityTool
{
protected:
    std::string securityLevel;
    double cost;
    int numDevices;
public:
    SecurityTool(std::string level, double c, int n)
        : securityLevel(level), cost(c), numDevices(n)
    {
        if (securityLevel != "High" && securityLevel != "Medium" && securityLevel != "Low")
        {
            std::cout << "Invalid security level. Setting to Low." << std::endl;
            securityLevel = "Low";
        }

        if (cost <= 0)
        {
            std::cout << "Invalid cost. Setting to 1." << std::endl;
            cost = 1;
        }
    }

    void performScan() const
    {
        std::cout << "Performing Security Scan....." << std::endl;
    }
};

class FirewallTool : public SecurityTool
{
private:
    int ports[24];
    std::string protocols[6];
public:
    FirewallTool(std::string l, double c, int n) : SecurityTool(l, c, n)
    {
        int startPort = 2;
        int endPort = 24;

        for (int i = startPort; i <= endPort; i++)
        {
            ports[i - startPort] = i;
        }

        // Protocol List
        protocols[0] = "HTTPS";
        protocols[1] = "FTP";
        protocols[2] = "UDP";
        protocols[3] = "ICMP";
        protocols[4] = "SSH";
        protocols[5] = "SNMP";
    }

    void generateList()
    {

        std::cout << "Allowed Ports: " << std::endl;
        for (int i = 0; i < 23; i++)
        {
            std::cout << ports[i] << " ";
        }
        std::cout << std::endl;
    }

    void performScan() const
    {
        SecurityTool::performScan();

        std::cout << "Performing Firewall Scan...." << std::endl;
        std::cout << "Allowed Protocols: " << std::endl;

        for (int i = 0; i < 6; i++)
        {
            std::cout << protocols[i] << " ";
        }
        std::cout << std::endl;

        if (securityLevel == "High")
        {
            std::cout << "Only traffic from allowed ports and protocols is allowed." << std::endl;
        }
        else if (securityLevel == "Medium")
        {
            std::cout << "Additional ports 25 and 26 are allowed." << std::endl;
        }
        else if (securityLevel == "Low")
        {
            std::cout << "Additional ports 25 - 30 are allowed, along with TCP and DNS protocols." << std::endl;
        }
    }
};

int main()
{
    FirewallTool firewall("High", 2000, 5);
    std::cout << "Layyana Junaid [23k0056]" << std::endl;

    firewall.generateList();
    firewall.performScan();
}
