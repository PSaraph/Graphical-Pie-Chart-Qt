#=============================================================================
#This is a Program to demonstrate a Graphics Pie Application with some effects.
#Copyright (C) 2015  Pradyumna Pramod Saraph
#Contact: prady.pps@gmail.com
#
#This program is free software: you can redistribute it and/or modify
#it under the terms of the Lesser GNU General Public License as published by
#the Free Software Foundation, either version 3 of the License, or
#(at your option) any later version.
#
#This program is distributed in the hope that it will be useful,
#but WITHOUT ANY WARRANTY; without even the implied warranty of
#MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#Lesser GNU General Public License for more details.
#
#You should have received a copy of the Lesser GNU General Public License
#along with this program.  If not, see <http://www.gnu.org/licenses/>.
#=============================================================================
#-------------------------------------------------
#
# Project created by QtCreator 2015-01-24T19:43:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicalPieChart
TEMPLATE = app


SOURCES += main.cpp\
        CMainWindow.cpp \
    pie/CGraphicsPieWidget.cpp \
    pie/CGraphicsPieView.cpp \
    pie/CGraphicsPieItem.cpp \
    Utils/CGenUtils.cpp

HEADERS  += CMainWindow.h \
    pie/CGraphicsPieWidget.h \
    pie/CGraphicsPieView.h \
    pie/CGraphicsPieItem.h \
    Utils/CGenUtils.h
