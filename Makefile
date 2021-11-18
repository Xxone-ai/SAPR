#############################################################################
# Makefile for building: SAPR
# Generated by qmake (3.1) (Qt 6.0.1)
# Project:  SAPR.pro
# Template: app
# Command: C:\Qt\6.0.1\mingw81_64\bin\qmake.exe -o Makefile SAPR.pro -spec win32-g++ "CONFIG+=qtquickcompiler"
#############################################################################

MAKEFILE      = Makefile

EQ            = =

first: release
install: release-install
uninstall: release-uninstall
QMAKE         = C:\Qt\6.0.1\mingw81_64\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = C:\Qt\6.0.1\mingw81_64\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = C:\Qt\6.0.1\mingw81_64\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
IDC           = idc
IDL           = midl
ZIP           = zip -r -9
DEF_FILE      = 
RES_FILE      = 
SED           = $(QMAKE) -install sed
MOVE          = move
SUBTARGETS    =  \
		release \
		debug


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

Makefile: SAPR.pro ../6.0.1/mingw81_64/mkspecs/win32-g++/qmake.conf ../6.0.1/mingw81_64/mkspecs/features/spec_pre.prf \
		../6.0.1/mingw81_64/mkspecs/features/device_config.prf \
		../6.0.1/mingw81_64/mkspecs/common/sanitize.conf \
		../6.0.1/mingw81_64/mkspecs/common/gcc-base.conf \
		../6.0.1/mingw81_64/mkspecs/common/g++-base.conf \
		../6.0.1/mingw81_64/mkspecs/features/win32/windows_vulkan_sdk.prf \
		../6.0.1/mingw81_64/mkspecs/common/windows-vulkan.conf \
		../6.0.1/mingw81_64/mkspecs/common/g++-win32.conf \
		../6.0.1/mingw81_64/mkspecs/common/windows-desktop.conf \
		../6.0.1/mingw81_64/mkspecs/qconfig.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_ext_freetype.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_ext_libpng.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_concurrent.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_concurrent_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_core.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_core_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_core_qobject_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_dbus.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_dbus_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_designer.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_designer_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_entrypoint_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_fb_support_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_gui.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_gui_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_help.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_help_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_linguist.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_linguist_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_network.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_network_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_opengl.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_opengl_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_openglwidgets.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_openglwidgets_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_printsupport.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_printsupport_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qml.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qml_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmlcompiler_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmldebug_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmlmodels.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmlmodels_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmltest.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmltest_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmlworkerscript.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmlworkerscript_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quick.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quick_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2impl.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2impl_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickshapes_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quicktemplates2.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickwidgets.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_sql.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_sql_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_svg.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_svg_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_svgwidgets.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_svgwidgets_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_testlib.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_testlib_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_tools_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_uiplugin.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_uitools.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_uitools_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_widgets.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_widgets_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_xml.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_xml_private.pri \
		../6.0.1/mingw81_64/mkspecs/modules/qt_lib_zlib_private.pri \
		../6.0.1/mingw81_64/mkspecs/features/qt_functions.prf \
		../6.0.1/mingw81_64/mkspecs/features/qt_config.prf \
		../6.0.1/mingw81_64/mkspecs/win32-g++/qmake.conf \
		../6.0.1/mingw81_64/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../6.0.1/mingw81_64/mkspecs/features/exclusive_builds.prf \
		../6.0.1/mingw81_64/mkspecs/features/toolchain.prf \
		../6.0.1/mingw81_64/mkspecs/features/default_pre.prf \
		../6.0.1/mingw81_64/mkspecs/features/win32/default_pre.prf \
		../6.0.1/mingw81_64/mkspecs/features/resolve_config.prf \
		../6.0.1/mingw81_64/mkspecs/features/exclusive_builds_post.prf \
		../6.0.1/mingw81_64/mkspecs/features/default_post.prf \
		../6.0.1/mingw81_64/mkspecs/features/qtquickcompiler.prf \
		../6.0.1/mingw81_64/mkspecs/features/entrypoint.prf \
		../6.0.1/mingw81_64/mkspecs/features/precompile_header.prf \
		../6.0.1/mingw81_64/mkspecs/features/warn_on.prf \
		../6.0.1/mingw81_64/mkspecs/features/qt.prf \
		../6.0.1/mingw81_64/mkspecs/features/resources_functions.prf \
		../6.0.1/mingw81_64/mkspecs/features/resources.prf \
		../6.0.1/mingw81_64/mkspecs/features/moc.prf \
		../6.0.1/mingw81_64/mkspecs/features/win32/opengl.prf \
		../6.0.1/mingw81_64/mkspecs/features/uic.prf \
		../6.0.1/mingw81_64/mkspecs/features/qmake_use.prf \
		../6.0.1/mingw81_64/mkspecs/features/file_copies.prf \
		../6.0.1/mingw81_64/mkspecs/features/win32/windows.prf \
		../6.0.1/mingw81_64/mkspecs/features/testcase_targets.prf \
		../6.0.1/mingw81_64/mkspecs/features/exceptions.prf \
		../6.0.1/mingw81_64/mkspecs/features/yacc.prf \
		../6.0.1/mingw81_64/mkspecs/features/lex.prf \
		SAPR.pro \
		../6.0.1/mingw81_64/lib/Qt6Widgets.prl \
		../6.0.1/mingw81_64/lib/Qt6Gui.prl \
		../6.0.1/mingw81_64/lib/Qt6Core.prl \
		../6.0.1/mingw81_64/lib/Qt6EntryPoint.prl \
		../6.0.1/mingw81_64/mkspecs/features/build_pass.prf
	$(QMAKE) -o Makefile SAPR.pro -spec win32-g++ "CONFIG+=qtquickcompiler"
../6.0.1/mingw81_64/mkspecs/features/spec_pre.prf:
../6.0.1/mingw81_64/mkspecs/features/device_config.prf:
../6.0.1/mingw81_64/mkspecs/common/sanitize.conf:
../6.0.1/mingw81_64/mkspecs/common/gcc-base.conf:
../6.0.1/mingw81_64/mkspecs/common/g++-base.conf:
../6.0.1/mingw81_64/mkspecs/features/win32/windows_vulkan_sdk.prf:
../6.0.1/mingw81_64/mkspecs/common/windows-vulkan.conf:
../6.0.1/mingw81_64/mkspecs/common/g++-win32.conf:
../6.0.1/mingw81_64/mkspecs/common/windows-desktop.conf:
../6.0.1/mingw81_64/mkspecs/qconfig.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_ext_freetype.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_ext_libpng.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_concurrent.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_concurrent_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_core.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_core_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_core_qobject_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_dbus.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_dbus_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_designer.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_designer_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_designercomponents_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_entrypoint_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_fb_support_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_gui.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_gui_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_help.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_help_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_linguist.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_linguist_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_network.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_network_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_opengl.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_opengl_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_openglwidgets.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_openglwidgets_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_packetprotocol_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_printsupport.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_printsupport_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qml.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qml_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmlcompiler_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmldebug_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmlmodels.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmlmodels_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmltest.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmltest_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmlworkerscript.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_qmlworkerscript_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quick.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quick_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2impl.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickcontrols2impl_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickparticles_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickshapes_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quicktemplates2.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickwidgets.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_sql.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_sql_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_svg.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_svg_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_svgwidgets.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_svgwidgets_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_testlib.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_testlib_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_tools_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_uiplugin.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_uitools.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_uitools_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_widgets.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_widgets_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_xml.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_xml_private.pri:
../6.0.1/mingw81_64/mkspecs/modules/qt_lib_zlib_private.pri:
../6.0.1/mingw81_64/mkspecs/features/qt_functions.prf:
../6.0.1/mingw81_64/mkspecs/features/qt_config.prf:
../6.0.1/mingw81_64/mkspecs/win32-g++/qmake.conf:
../6.0.1/mingw81_64/mkspecs/features/spec_post.prf:
.qmake.stash:
../6.0.1/mingw81_64/mkspecs/features/exclusive_builds.prf:
../6.0.1/mingw81_64/mkspecs/features/toolchain.prf:
../6.0.1/mingw81_64/mkspecs/features/default_pre.prf:
../6.0.1/mingw81_64/mkspecs/features/win32/default_pre.prf:
../6.0.1/mingw81_64/mkspecs/features/resolve_config.prf:
../6.0.1/mingw81_64/mkspecs/features/exclusive_builds_post.prf:
../6.0.1/mingw81_64/mkspecs/features/default_post.prf:
../6.0.1/mingw81_64/mkspecs/features/qtquickcompiler.prf:
../6.0.1/mingw81_64/mkspecs/features/entrypoint.prf:
../6.0.1/mingw81_64/mkspecs/features/precompile_header.prf:
../6.0.1/mingw81_64/mkspecs/features/warn_on.prf:
../6.0.1/mingw81_64/mkspecs/features/qt.prf:
../6.0.1/mingw81_64/mkspecs/features/resources_functions.prf:
../6.0.1/mingw81_64/mkspecs/features/resources.prf:
../6.0.1/mingw81_64/mkspecs/features/moc.prf:
../6.0.1/mingw81_64/mkspecs/features/win32/opengl.prf:
../6.0.1/mingw81_64/mkspecs/features/uic.prf:
../6.0.1/mingw81_64/mkspecs/features/qmake_use.prf:
../6.0.1/mingw81_64/mkspecs/features/file_copies.prf:
../6.0.1/mingw81_64/mkspecs/features/win32/windows.prf:
../6.0.1/mingw81_64/mkspecs/features/testcase_targets.prf:
../6.0.1/mingw81_64/mkspecs/features/exceptions.prf:
../6.0.1/mingw81_64/mkspecs/features/yacc.prf:
../6.0.1/mingw81_64/mkspecs/features/lex.prf:
SAPR.pro:
../6.0.1/mingw81_64/lib/Qt6Widgets.prl:
../6.0.1/mingw81_64/lib/Qt6Gui.prl:
../6.0.1/mingw81_64/lib/Qt6Core.prl:
../6.0.1/mingw81_64/lib/Qt6EntryPoint.prl:
../6.0.1/mingw81_64/mkspecs/features/build_pass.prf:
qmake: FORCE
	@$(QMAKE) -o Makefile SAPR.pro -spec win32-g++ "CONFIG+=qtquickcompiler"

qmake_all: FORCE

make_first: release-make_first debug-make_first  FORCE
all: release-all debug-all  FORCE
clean: release-clean debug-clean  FORCE
distclean: release-distclean debug-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
mocclean: release-mocclean debug-mocclean

release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
mocables: release-mocables debug-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Release: Makefile
$(MAKEFILE).Debug: Makefile
