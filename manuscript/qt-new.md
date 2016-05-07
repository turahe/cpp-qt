# What's New in Qt 5

Qt 5 is the latest version of Qt. It enables developers to develop applications with intuitive user interfaces for multiple targets, faster than ever before. Qt 5 makes it easier to address the latest UI paradigm shifts that touch screens and tablets require.

Developers can be more productive and flexible with the improved support for JavaScript and QML in Qt 5, while still having the C++ foundation and Qt Widget support. HTML5 developers will feel at home with the Web offering that includes Chromium-based Qt WebEngine and Qt [WebChannel](http://doc.qt.io/qt-5/qml-qtwebchannel-webchannel.html).

Qt 5 is highly compatible with Qt 4. It is possible for developers of Qt 4 applications to seamlessly move on to Qt 5 with their current functionality and gradually develop new things leveraging all the great items Qt 5 makes possible.

Cross-platform portability is made simpler in Qt 5, thanks to the new modularized codebase consisting of the [essential and add-on modules](http://doc.qt.io/qt-5/qtmodules.html), and the consolidation of the [Qt Platform Abstraction](http://doc.qt.io/qt-5/qpa.html).

The following sections summarize some of the key features that Qt 5 brings to the table.

## Qt Everywhere on Mobile



Qt now comes with production-ready ports for Android, iOS, and WinRT (including Windows Phone 8). Extensive work has gone into these platform ports, which now extend Qt’s multi-platform promise to cover desktop, embedded, and mobile platforms.

With full support for Android, iOS, and WinRT, Qt is a great solution for targeting the mobile markets with a single codebase. It is fast and easy to bring existing desktop or embedded application to mobile, by simply recompiling it.

You can install several demo applications that showcase the power of Qt on these mobile platforms. Here is a small list of such applications:

Demo applications:

1.     [Introduction to Qt 5](https://play.google.com/store/apps/details?id=com.digia.Qt5Intro) (Google Play)
1.     [Qt 5 Everywhere](https://play.google.com/store/apps/details?id=com.digia.Qt5Everywhere) (Google Play)
1.     [SubAttack ](https://itunes.apple.com/us/app/subattack/id659283830)(App Store)
1.     [QtQuicksand](https://itunes.apple.com/us/app/qtquicksand/id666273528) (App Store)
1.     Quick Forecast on [App Store](https://itunes.apple.com/us/app/quick-forecast/id736658981), [Google Play](https://play.google.com/store/apps/details?id=org.qtproject.quickforecast), and [Windows Store](http://www.windowsphone.com/en-us/store/app/quickforecast/35572287-c6d6-4d5c-9799-46555f7fc459).
1.     Qt Hangman on [App Store](https://itunes.apple.com/us/app/qt-hangman/id762381104) and [Google Play](https://play.google.com/store/apps/details?id=com.digia.QtHangman)
1.     Flyingbus on [App Store](https://itunes.apple.com/us/app/flyingbus/id762515926?mt=8) and [Google Play](https://play.google.com/store/apps/details?id=com.digia.Flyingbus)

Platform pages:

1.     Qt for [Android](http://doc.qt.io/qt-5/android-support.html)
1.     Qt for [iOS](http://doc.qt.io/qt-5/ios-support.html)
1.     Qt for [WinRT](http://doc.qt.io/qt-5/winrt-support.html)

	
![Qt Everywhere demo on Nexus 7](images/demo1.jpg)

Amazing Graphics Capability and Performance

## haderEffect on an Image
	
![ShaderEffect on an Image](images/demo2.jpg)

Qt 5 uses an OpenGL-based scene graph to accelerate the graphics of Qt Quick, making it possible to do visually appealing user interfaces with animations, impressive graphical effects and particle systems, even on the constrained hardware environments of mobile and embedded devices.

The benefits of this architectural change in the rendering engine are well demonstrated by the following projects:

-     [Livecoding video effects with Qt5](http://qt-project.org/videos/watch/livecoding-video-effects-with-qt5) The Big Buck Bunny you never saw before. Video effects created using Qt Quick.
-     [Pimp my video](http://blog.qt.io/2012/02/29/pimp-my-video-shader-effects-and-multimedia/) Video effects implemented using the shader language with QML.
-     [QtMediaHub](http://wiki.qt.io/QtMediaHub) The power and convenience of Qt Quick.
-     [QtonPi](http://wiki.qt.io/Qt_RaspberryPi) Good example of Qt 5 running on the low cost hardware, Raspberry PI.

## Qt Quick in Qt 5

[Qt Quick](http://doc.qt.io/qt-5/qtquick-index.html) provides the necessary infrastructure to develop QML applications. The latest version (v2.0) of this technology also introduces a set of new C++ classes as a replacement for the `QDeclarative*` equivalents in Qt Quick 1. New features in Qt Quick include:

-     [Canvas](http://doc.qt.io/qt-5/qml-qtquick-canvas.html) for drawing. Canvas provides an API that is similar to the HTML5 Canvas API, along with some additional features.
-     [Shader Effects](http://doc.qt.io/qt-5/qml-qtquick-shadereffect.html) which enable GLSL shader programs to be integrated directly into QML code and applied to items and images.
-     [Particle Effects](http://doc.qt.io/qt-5/qtquick-effects-particles.html) for creating a variety of 2D particle systems.
-     [Sprites](http://doc.qt.io/qt-5/qtquick-effects-sprites.html) can be used in animating 2D graphical objects and as a source for particle systems.
-     [Offline storage](http://doc.qt.io/qt-5/qtquick-localstorage-qmlmodule.html) is a JavaScript API that conforms with the HTML5 Web Database API for storing data in Qt Quick applications.
-     [Window](http://doc.qt.io/qt-5/qtquick-window-qmlmodule.html) provides a top-level window and the Screen type for accessing a screen's resolution and other details. This is useful for desktop applications developed using Qt Quick.
-     [OpenGL-based rendering architecture](http://doc.qt.io/qt-5/topics-graphics.html#qt-quick-scene-graph) for optimal performance.

![Qt Quick's Particle System](images/demo3.jpg)


The [Qt Graphical Effects](http://doc.qt.io/qt-5/qtgraphicaleffects-index.html) module provides a number of ready-made effects for use in Qt Quick applications, including soft drop shadow, blur, glow and colorize.
	
![Excerpts from the Qt Graphical Effects module](images/demo4.jpg)

## Designing UI Made Simpler

![Controls gallery example on Android](images/demo4.png)

	
![Controls gallery example on OS X](images/demo5.png)

	

UI designing can be time consuming if there are not enough tools to help. Qt Quick does reduce the effort considerably compared to the traditional native (C or C++) approach, but the new [Qt Quick Controls](http://doc.qt.io/qt-5/qtquickcontrols-index.html) and [Qt Quick Layouts](http://doc.qt.io/qt-5/qtquicklayouts-index.html) take it a step further. These new modules provide ready-to-use UI controls and layouts to enable faster application development and with less code.

Qt Quick Controls and Qt Quick Layouts provide a vast set of UI controls ranging from the most basic [TextField](http://doc.qt.io/qt-5/qml-qtquick-controls-textfield.html) and Button to the more complex [TableView](http://doc.qt.io/qt-5/qml-qtquick-controls-tableview.html) and [TabView](http://doc.qt.io/qt-5/qml-qtquick-controls-tabview.html). These controls are also made available in [Qt Quick Designer](http://doc.qt.io/qtcreator/creator-using-qt-quick-designer.html).

## Sensor and Location

Reacting to sensor value changes and locating a place on the world map are the common use cases supported on most portable devices. Now you can support such use cases in your Qt application using the [Qt Sensors](http://doc.qt.io/qt-5/qtsensors-index.html) and [Qt Positioning](http://doc.qt.io/qt-5/qtpositioning-index.html) modules.

![Accelerating SVG image](images/demo6.jpg)
	

![Location-based weather information](images/demo7.jpg)

## Web Engine and HTML5

![Qt Quick nano browser](images/qt-webengine.jpg)
	

[Qt WebEngine](http://doc.qt.io/qt-5/qtwebengine-index.html) is a web content rendering engine based on Chromium featuring broad support for standard web technologies. It provides integration with both Qt Quick and traditional widgets. The module brings the latest in HTML5 advancements to Qt 5, including CSS filters, animations and video, and Canvas.

This Chromium-based Web Engine support in Qt is complemented with [Qt WebChannel](http://doc.qt.io/qt-5/qtwebchannel-index.html), which bridges the gap between QML/C++ and HTML/JavaScript. It enables sharing QObjects from QML/C++ with HTML/JavaScript-based clients.

## Multimedia

[Qt Multimedia](http://doc.qt.io/qt-5/qtmultimedia-index.html) provides a rich set of QML types and C++ classes to handle multimedia content. It also provides necessary APIs to access the camera and radio functionality. Qt 5 brings the Qt Multimedia module into the set of essential modules with support on all major platforms.
	

![Video embedded into a Qt Quick application with a displacement effect Platform-specific Extras](images/qt-multimedia.jpg)

Qt is a cross-platform development framework enabling you to target multiple platforms with a single codebase. It provides common APIs across all supported platforms to access a feature without having to worry about how that feature is implemented on a platform. In some applications there will be a need to use a platform-specific feature, and that's when the following modules can be useful:

-     [Qt Android Extras](http://doc.qt.io/qt-5/qtandroidextras-index.html) enables you to integrate Java code into your Qt application.
-     [Qt Mac Extras](http://doc.qt.io/qt-5/qtmacextras-index.html) enables you to access specific features on OS X and iOS.
-     [Qt Windows Extras](http://doc.qt.io/qt-5/qtwinextras-index.html) enables you to use Windows-specific features such as jump lists, progress indicator on a taskbar button, and so on.
-     [Qt X11 Extras](http://doc.qt.io/qt-5/qtx11extras-index.html) enables you to access the display configuration on Linux (X11).

## Modularized Qt Libraries

Qt 5 splits the Qt libraries into domain specific libraries and modules. This means that an application can choose which libraries it requires and only compile, use and deploy those.

For a complete list of modules and libraries, see [all Qt modules](http://doc.qt.io/qt-5/qtmodules.html).

### Widgets in Qt 5

The [Qt Widgets](http://doc.qt.io/qt-5/qtwidgets-index.html) have been separated into their own module in Qt 5, the Qt Widgets module. It is part of the essential modules.

![Screen capture of a widget application.](images/qt-widget.jpg)

Designing the UI for widget-based applications can be quick with [Qt Designer](http://doc.qt.io/qt-5/qtdesigner-manual.html).

## Provide Map-based Solutions with Qt

In today's world, location and maps information is more widely used, be it to look up nearby restaurants or plan commute to the office. With Qt, it is now possible to cater to these usecases by consuming map data provided by the third-party vendors. The [Qt Location](http://doc.qt.io/qt-5/qtlocation-module.html) module provides the APIs and the necessary backend to fetch map data from some of the popular third-party mapping solutions. Here is a snapshot of the demo application running on Android, presenting OpenStreetMap data from [www.mapquest.com](http://www.mapquest.com/).
	

![Mapviewer example screenshot](images/qt-maps.jpg)

## Qt Platform Abstraction

The windowing system dependent parts of Qt have been completely rewritten for Qt 5, based on the Qt Platform Abstraction, a plugin architecture which allows Qt to dynamically load a windowing system integration based on what system it is running on. This gives several benefits:

-     Centralize the windowing system integration codebase into classes shared for all platforms.
-     Simplify the work required when porting Qt to new platforms.
-     Remove the windowing system dependency from Qt, making it possible to have the same Qt binaries run against multiple windowing systems. For instance, the Qt Linux binaries can run against both X11 and Wayland.

## New Connection Syntax

In addition to the still available well known way to connect signals and slots, new overloads of [QObject::connect](http://doc.qt.io/qt-5/qobject.html#connect) have been added allowing you to connect signals and slot using pointer to member functions:

```c++
QObject::connect(sender, &Sender::valueChanged, receiver, &Receiver::updateValue);
```

The new syntax provides compile time checking of the compatibility between signals and slots, automatic conversion of the arguments if there is an implicit cast between the types, and solve many problems occurring because of typedef or namespaces.

Additionally, if your compiler supports C++11 lambdas, you can even connect directly to a lambda function.

```c++
connect(sender, &QObject::destroyed, [=](){ this->m_objects.remove(sender); });
```

For a detailed comparison with the original string-based syntax, see [Differences between String-Based and Functor-Based Connections](http://doc.qt.io/qt-5/signalsandslots-syntaxes.html).

## Connectivity and Networking

Qt 5 provides better support for IPv6 and dual mode networks. Most applications using host names and network layer transparent protocols can now gain IPv6 support transparently. Such applications can also choose to receive both IPv4 and IPv6 connections or bind to only one of the two connection types. In the case of outgoing HTTP connections using QNetworkAccessManager, both IPv4 and IPv6 connections are attempted in parallel, and the one that succeeds first is used. This is useful in environments where one of the two types has limited connectivity.

Qt 5 also provides better ways to handle TCP socket-based connections and SSL certificates. This means developers can now:

-     bind a TCP socket to an IP address before connecting,
-     verify an SSL certificate chain,
-     and access legacy systems.

Stricter client authentication is one of the primary concerns for many applications handling confidential or critical data. The opaque Private Keys support in Qt 5 enables applications to read private keys from devices such as PKCS#11 dongles for stricter client authentication. The [qsslkey example ](http://git.iksaif.net/?p=qsslkey-p11.git)illustrates reading private keys from a device.

### Extended Connectivity

The connectivity options are endless with Qt 5. The two new modules, Qt Bluetooth and Qt NFC, enable developers to add support for sophisticated ways to connect and share information in their application.

## JSON Support

Qt applications that use simple data structures to store small amount of data, can now choose to use JSON documents over the complex database backends that need necessary drivers or plugins to access data. The fact that JSON is a text-based open standard derived from JavaScript, makes it the obvious choice for QML applications as well.

The Qt Core provides a set of classes to enable parsing and generating JSON documents. These classes also allow you to convert between an in-memory binary representation of JSON to a standard textual JSON format. The goal is to make common operations on JSON faster.

## User Input

Qt 4 already had support for handling multi-point touch input in C++. Qt 5 extends this support to include Qt Quick, covering all the information about the touch points, including the touch position, pressure, and velocity.

The mouse event handling in Qt 5 has been improved from its predecessor. Applications have more control to handle mouse events in Qt Quick. The mouse area in a QML document can propagate the mouse wheel and click events and also ignore propagated events.

Besides this, Qt 5 adds support for more mouse buttons on platforms where this is supported. This comes in handy for gaming applications developed using Qt.