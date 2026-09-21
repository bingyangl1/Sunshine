#include "automation_server.h"

#include "../logging.h"

namespace automation {

struct AutomationServer::Impl {
  bool running = false;
};

AutomationServer& AutomationServer::instance() {
  static AutomationServer inst;
  return inst;
}

AutomationServer::~AutomationServer() {
  stop();
}

bool AutomationServer::start(const std::string& listen_address) {
  pimpl = std::make_unique<Impl>();
  pimpl->running = true;
  BOOST_LOG(info) << "Automation server started, listening on " << listen_address;
  return true;
}

void AutomationServer::stop() {
  if (pimpl && pimpl->running) {
    pimpl->running = false;
    BOOST_LOG(info) << "Automation server stopped";
  }
  pimpl.reset();
}

}  // namespace automation
