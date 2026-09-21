#pragma once

#include <memory>
#include <string>

namespace automation {

/**
 * @brief 游戏自动化服务模块
 *
 * 提供HTTP/WS接口接收外部脚本的控制指令，
 * 桥接Sunshine原生输入能力，支持画面帧回传，
 * 用于实现游戏自动化闭环场景。
 */
class AutomationServer {
public:
  /**
   * @brief 获取单例实例
   *
   * @return 全局唯一AutomationServer实例
   */
  static AutomationServer& instance();

  ~AutomationServer();

  AutomationServer(const AutomationServer&) = delete;
  AutomationServer& operator=(const AutomationServer&) = delete;

  /**
   * @brief 初始化并启动自动化服务
   *
   * 在Sunshine主服务启动时调用，绑定现有HTTPS端口，注册自动化路由
   *
   * @param listen_address 监听地址，默认复用47984端口
   * @return 启动是否成功
   */
  bool start(const std::string& listen_address = "0.0.0.0:47984");

  /**
   * @brief 停止自动化服务，释放资源
   *
   * 在Sunshine主服务退出时调用
   */
  void stop();

private:
  AutomationServer() = default;

  struct Impl;
  std::unique_ptr<Impl> pimpl;
};

}  // namespace automation
