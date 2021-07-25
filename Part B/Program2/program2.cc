#include <fstream>
#include "ns3/core-module.h"
#include "ns3/csma-module.h"
#include "ns3/applications-module.h"
#include "ns3/internet-module.h"
#include "ns3/netanim-module.h"

using namespace ns3;

int main(int argc, char *argv[]) {
	Address serverAddress;
	NodeContainer n;
	n.Create(4);
	InternetStackHelper internet;
	internet.Install(n);
	CsmaHelper csma;
	csma.SetChannelAttribute ("DataRate", DataRateValue(DataRate(5000000)));
	csma.SetChannelAttribute("Delay", TimeValue(MilliSeconds(2)));
	csma.SetDeviceAttribute("Mtu", UintegerValue(1400));
	NetDeviceContainer d = csma.Install(n);
	Ipv4AddressHelper ipv4;
	ipv4.SetBase("10.1.1.0", "255.255.255.0");
	Ipv4InterfaceContainer i = ipv4.Assign(d);
	serverAddress = Address(i.GetAddress(1));

	uint16_t port = 9;
	UdpEchoServerHelper server (port);
	ApplicationContainer apps = server.Install(n.Get(1));
	apps.Start(Seconds(1.0));
	apps.Stop(Seconds(10.0));

	uint32_t packetSize = 1024;
	uint32_t maxPacketCount = 1;
	Time InterPacketInterval = Seconds (1.);
	UdpEchoClientHelper client(serverAddress, port);
	client.SetAttribute("MaxPackets", UintegerValue(maxPacketCount));
	client.SetAttribute("Interval", TimeValue(InterPacketInterval));
	client.SetAttribute("PacketSize", UintegerValue(packetSize));
	apps = client.Install(n.Get(0));
	apps.Start(Seconds(2.0));
	apps.Stop(Seconds(10.0));

	#if 0
	client.SetFill(apps.Get(0), "Hello World");
	client.SetFill(apps.GEt(0), 0xa5, 1024);
	uint8_t fill[] = {0,1,2,3,4,5,6};
	client.SetFill (apps.Get(0), fill, sizeof(fill), 1024);
	#endif

	AnimationInterface anim ("second.xml");
	Simulator::Run();
	Simulator::Destroy();
}
