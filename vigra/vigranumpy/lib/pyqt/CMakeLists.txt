SET(PYSOURCES
    __init__.py
    imagewindow.py
    quickdialog.py
    overlays.py
    )

INSTALL(FILES ${PYSOURCES} DESTINATION ${VIGRANUMPY_INSTALL_DIR}/vigra/pyqt)
