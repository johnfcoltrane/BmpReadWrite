Attribute VB_Name = "CommonDir"
Option Explicit
Function min(x As Integer, y As Integer)
    If x > y Then
        min = y
    Else
        min = x
    End If
End Function

Function getCommonParentDir(a, b) '(a As Valiant, b As Valiant) 'As Valiant
Dim i As Integer
Dim v As Collection
    Set v = New Collection
    Dim n As Integer
    n = min(CInt(UBound(a)), CInt(UBound(b)))
    For i = 0 To n
        If a(i) = b(i) Then
            v.Add a(i)
        Else
            Exit For
        End If
    Next
    Set getCommonParentDir = v
End Function

Sub test1()
Dim v As Collection
Dim a As Variant
Dim b As Variant
    a = Array("a", "b", "c", "d", "e")
    b = Array("a", "b", "c", "x", "y")
    Set v = getCommonParentDir(a, b)
    Stop
End Sub
