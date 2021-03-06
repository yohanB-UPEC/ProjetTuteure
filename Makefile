#############################################################################
# Makefile for building: projet
# Generated by qmake (3.1) (Qt 5.12.11)
# Project:  projet.pro
# Template: app
# Command: C:\qt5-build\qtbase\bin\qmake.exe -o Makefile projet.pro -spec win32-g++
#############################################################################

MAKEFILE      = Makefile

EQ            = =

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = C:\qt5-build\qtbase\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = C:\qt5-build\qtbase\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = C:\qt5-build\qtbase\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: projet.pro C:/qt5/qtbase/mkspecs/win32-g++/qmake.conf C:/qt5/qtbase/mkspecs/features/spec_pre.prf \
		C:/qt5-build/qtbase/mkspecs/qdevice.pri \
		C:/qt5/qtbase/mkspecs/features/device_config.prf \
		C:/qt5/qtbase/mkspecs/common/sanitize.conf \
		C:/qt5/qtbase/mkspecs/common/gcc-base.conf \
		C:/qt5/qtbase/mkspecs/common/g++-base.conf \
		C:/qt5/qtbase/mkspecs/common/angle.conf \
		C:/qt5/qtbase/mkspecs/features/win32/windows_vulkan_sdk.prf \
		C:/qt5/qtbase/mkspecs/common/windows-vulkan.conf \
		C:/qt5/qtbase/mkspecs/common/g++-win32.conf \
		C:/qt5-build/qtbase/mkspecs/qconfig.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_ext_freetype.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_ext_harfbuzz.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_ext_libpng.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_ext_pcre2.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axbase.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axbase_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axcontainer.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axcontainer_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axserver.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axserver_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_bootstrap_dbus_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_bootstrap_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_concurrent.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_concurrent_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_core.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_core_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_dbus.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_dbus_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_edid_support_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_fb_support_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_gui.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_gui_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_network.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_network_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_networkauth.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_networkauth_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_opengl.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_opengl_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_openglextensions.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_openglextensions_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_printsupport.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_printsupport_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_serialbus.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_serialbus_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_serialport.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_serialport_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_sql.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_sql_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_svg.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_svg_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_testlib.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_testlib_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_theme_support_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_widgets.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_widgets_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_windowsuiautomation_support_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_xml.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_lib_xml_private.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_tool_canbusutil.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_tool_dumpcpp.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_tool_dumpdoc.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_tool_qdbuscpp2xml.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_tool_qdbusxml2cpp.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_tool_qlalr.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_tool_qvkgen.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_tool_syncqt.pri \
		C:/qt5-build/qtbase/mkspecs/modules/qt_tool_uic.pri \
		C:/qt5/qtbase/mkspecs/features/qt_functions.prf \
		C:/qt5/qtbase/mkspecs/features/qt_config.prf \
		C:/qt5/qtbase/mkspecs/win32-g++/qmake.conf \
		C:/qt5/qtbase/mkspecs/features/spec_post.prf \
		.qmake.stash \
		C:/qt5/qtbase/mkspecs/features/exclusive_builds.prf \
		C:/qt5/qtbase/mkspecs/features/toolchain.prf \
		C:/qt5/qtbase/mkspecs/features/default_pre.prf \
		C:/qt5/qtbase/mkspecs/features/win32/default_pre.prf \
		C:/qt5/qtbase/mkspecs/features/resolve_config.prf \
		C:/qt5/qtbase/mkspecs/features/exclusive_builds_post.prf \
		C:/qt5/qtbase/mkspecs/features/default_post.prf \
		C:/qt5/qtbase/mkspecs/features/win32/console.prf \
		C:/qt5/qtbase/mkspecs/features/precompile_header.prf \
		C:/qt5/qtbase/mkspecs/features/warn_on.prf \
		C:/qt5/qtbase/mkspecs/features/qt.prf \
		C:/qt5/qtbase/mkspecs/features/resources.prf \
		C:/qt5/qtbase/mkspecs/features/moc.prf \
		C:/qt5/qtbase/mkspecs/features/win32/opengl.prf \
		C:/qt5/qtbase/mkspecs/features/uic.prf \
		C:/qt5/qtbase/mkspecs/features/qmake_use.prf \
		C:/qt5/qtbase/mkspecs/features/file_copies.prf \
		C:/qt5/qtbase/mkspecs/features/testcase_targets.prf \
		C:/qt5/qtbase/mkspecs/features/exceptions.prf \
		C:/qt5/qtbase/mkspecs/features/yacc.prf \
		C:/qt5/qtbase/mkspecs/features/lex.prf \
		projet.pro \
		C:/qt5-build/qtbase/lib/Qt5Widgets.prl \
		C:/qt5-build/qtbase/lib/Qt5Gui.prl \
		C:/qt5-build/qtbase/lib/Qt5Xml.prl \
		C:/qt5-build/qtbase/lib/Qt5Core.prl
	$(QMAKE) -o Makefile projet.pro -spec win32-g++
C:/qt5/qtbase/mkspecs/features/spec_pre.prf:
C:/qt5-build/qtbase/mkspecs/qdevice.pri:
C:/qt5/qtbase/mkspecs/features/device_config.prf:
C:/qt5/qtbase/mkspecs/common/sanitize.conf:
C:/qt5/qtbase/mkspecs/common/gcc-base.conf:
C:/qt5/qtbase/mkspecs/common/g++-base.conf:
C:/qt5/qtbase/mkspecs/common/angle.conf:
C:/qt5/qtbase/mkspecs/features/win32/windows_vulkan_sdk.prf:
C:/qt5/qtbase/mkspecs/common/windows-vulkan.conf:
C:/qt5/qtbase/mkspecs/common/g++-win32.conf:
C:/qt5-build/qtbase/mkspecs/qconfig.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_ext_freetype.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_ext_harfbuzz.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_ext_libpng.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_ext_pcre2.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_accessibility_support_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axbase.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axbase_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axcontainer.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axcontainer_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axserver.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_axserver_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_bootstrap_dbus_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_bootstrap_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_concurrent.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_concurrent_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_core.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_core_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_dbus.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_dbus_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_edid_support_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_fb_support_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_gui.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_gui_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_network.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_network_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_networkauth.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_networkauth_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_opengl.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_opengl_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_openglextensions.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_openglextensions_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_printsupport.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_printsupport_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_serialbus.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_serialbus_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_serialport.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_serialport_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_sql.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_sql_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_svg.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_svg_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_testlib.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_testlib_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_theme_support_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_widgets.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_widgets_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_windowsuiautomation_support_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_xml.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_lib_xml_private.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_tool_canbusutil.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_tool_dumpcpp.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_tool_dumpdoc.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_tool_qdbuscpp2xml.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_tool_qdbusxml2cpp.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_tool_qlalr.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_tool_qvkgen.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_tool_syncqt.pri:
C:/qt5-build/qtbase/mkspecs/modules/qt_tool_uic.pri:
C:/qt5/qtbase/mkspecs/features/qt_functions.prf:
C:/qt5/qtbase/mkspecs/features/qt_config.prf:
C:/qt5/qtbase/mkspecs/win32-g++/qmake.conf:
C:/qt5/qtbase/mkspecs/features/spec_post.prf:
.qmake.stash:
C:/qt5/qtbase/mkspecs/features/exclusive_builds.prf:
C:/qt5/qtbase/mkspecs/features/toolchain.prf:
C:/qt5/qtbase/mkspecs/features/default_pre.prf:
C:/qt5/qtbase/mkspecs/features/win32/default_pre.prf:
C:/qt5/qtbase/mkspecs/features/resolve_config.prf:
C:/qt5/qtbase/mkspecs/features/exclusive_builds_post.prf:
C:/qt5/qtbase/mkspecs/features/default_post.prf:
C:/qt5/qtbase/mkspecs/features/win32/console.prf:
C:/qt5/qtbase/mkspecs/features/precompile_header.prf:
C:/qt5/qtbase/mkspecs/features/warn_on.prf:
C:/qt5/qtbase/mkspecs/features/qt.prf:
C:/qt5/qtbase/mkspecs/features/resources.prf:
C:/qt5/qtbase/mkspecs/features/moc.prf:
C:/qt5/qtbase/mkspecs/features/win32/opengl.prf:
C:/qt5/qtbase/mkspecs/features/uic.prf:
C:/qt5/qtbase/mkspecs/features/qmake_use.prf:
C:/qt5/qtbase/mkspecs/features/file_copies.prf:
C:/qt5/qtbase/mkspecs/features/testcase_targets.prf:
C:/qt5/qtbase/mkspecs/features/exceptions.prf:
C:/qt5/qtbase/mkspecs/features/yacc.prf:
C:/qt5/qtbase/mkspecs/features/lex.prf:
projet.pro:
C:/qt5-build/qtbase/lib/Qt5Widgets.prl:
C:/qt5-build/qtbase/lib/Qt5Gui.prl:
C:/qt5-build/qtbase/lib/Qt5Xml.prl:
C:/qt5-build/qtbase/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile projet.pro -spec win32-g++

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) C:\Users\Yohan\Documents\DUT2\C++\ProjetTuteure\uic_wrapper.bat C:\Users\Yohan\Documents\DUT2\C++\ProjetTuteure\uic_wrapper.bat .qmake.stash

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
