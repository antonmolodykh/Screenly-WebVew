unix:!android {
    isEmpty(target.path) {
        target.path = /opt/$${TARGET}/bin
        export(target.path)
    }
    INSTALLS += target
}

export(INSTALLS)

