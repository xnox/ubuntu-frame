/*
 * Copyright © 2016-2020 Canonical Ltd.
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 or 3 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Authored By: Alan Griffiths <alan@octopull.co.uk>
 */

#ifndef MIRAL_X11_KIOSK_WINDOW_MANAGER_H
#define MIRAL_X11_KIOSK_WINDOW_MANAGER_H

#include <miral/canonical_window_manager.h>

#include <mir_toolkit/events/enums.h>

using namespace mir::geometry;

class FrameWindowManagerPolicy : public miral::CanonicalWindowManagerPolicy
{
public:
    using miral::CanonicalWindowManagerPolicy::CanonicalWindowManagerPolicy;

    auto place_new_window(miral::ApplicationInfo const& app_info, miral::WindowSpecification const& request)
    -> miral::WindowSpecification override;

    bool handle_keyboard_event(MirKeyboardEvent const* event) override;
    bool handle_touch_event(MirTouchEvent const* event) override;
    bool handle_pointer_event(MirPointerEvent const* event) override;
    void handle_modify_window(miral::WindowInfo& window_info, miral::WindowSpecification const& modifications) override;

    void handle_request_drag_and_drop(miral::WindowInfo& window_info) override;
    void handle_request_move(miral::WindowInfo& window_info, MirInputEvent const* input_event) override;
    void handle_request_resize(miral::WindowInfo& window_info, MirInputEvent const* input_event,
        MirResizeEdge edge) override;

    auto confirm_placement_on_display(const miral::WindowInfo& window_info, MirWindowState new_state,
        Rectangle const& new_placement) -> Rectangle override;

    void advise_begin() override;
    void advise_end() override;
    void advise_application_zone_create(miral::Zone const& application_zone) override;
    void advise_application_zone_update(miral::Zone const& updated, miral::Zone const& original) override;
    void advise_application_zone_delete(miral::Zone const& application_zone) override;

private:
    bool application_zones_have_changed = false;
};

#endif /* MIRAL_X11_KIOSK_WINDOW_MANAGER_H */
