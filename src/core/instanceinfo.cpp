#include "instanceinfo.hpp"

#include <qdatastream.h>

QDataStream& operator<<(QDataStream& stream, const InstanceInfo& info) {
	stream << info.instanceId << info.configPath << info.shellId << info.launchTime << info.pid
	       << info.display;
	return stream;
}

QDataStream& operator>>(QDataStream& stream, InstanceInfo& info) {
	stream >> info.instanceId >> info.configPath >> info.shellId >> info.launchTime >> info.pid
	    >> info.display;
	return stream;
}

QDataStream& operator<<(QDataStream& stream, const RelaunchInfo& info) {
	stream << info.instance << info.noColor << info.timestamp << info.sparseLogsOnly
	       << info.defaultLogLevel << info.logRules;

	return stream;
}

QDataStream& operator>>(QDataStream& stream, RelaunchInfo& info) {
	stream >> info.instance >> info.noColor >> info.timestamp >> info.sparseLogsOnly
	    >> info.defaultLogLevel >> info.logRules;

	return stream;
}

InstanceInfo InstanceInfo::CURRENT = {}; // NOLINT

namespace qs::crash {

CrashInfo CrashInfo::INSTANCE = {}; // NOLINT

}
