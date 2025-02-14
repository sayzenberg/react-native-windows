// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <Modules/AppThemeModule.h>

#include <winrt/Windows.UI.ViewManagement.h>

#include <cxxreact/MessageQueueThread.h>

#include <IReactInstance.h>

namespace react { namespace uwp {

class AppTheme : public react::windows::AppTheme
{
public:
  AppTheme(const std::shared_ptr<IReactInstance>& reactInstance, const std::shared_ptr<facebook::react::MessageQueueThread>& defaultQueueThread);
  virtual ~AppTheme();

  const std::string getCurrentTheme() override;

private:
  void fireEvent(std::string const& eventName, folly::dynamic&& eventData);

  std::weak_ptr<IReactInstance> m_wkReactInstance;
  std::shared_ptr<facebook::react::MessageQueueThread> m_queueThread;
  winrt::Windows::UI::Xaml::ApplicationTheme m_currentTheme{ winrt::Windows::UI::Xaml::ApplicationTheme::Light };

  winrt::Windows::UI::ViewManagement::AccessibilitySettings m_accessibilitySettings{ };
  winrt::Windows::UI::ViewManagement::UISettings m_uiSettings{ };
  winrt::Windows::UI::ViewManagement::UISettings::ColorValuesChanged_revoker m_colorValuesChangedRevoker{ };
};

} } // namespace react::uwp
