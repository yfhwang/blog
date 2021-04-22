# 简洁操作

将下面的代码命名为`cap_switch.reg`文件，双击打开，重启后为左ctrl和左alt互换，右ctrl和右alt互换。



```
Windows Registry Editor Version 5.00
 


[HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Keyboard Layout]

"Scancode Map"=hex:00,00,00,00,00,00,00,00,05,00,00,00,38,00,1D,00,1D,00,38,00,38,E0,1D,E0,1D,E0,38,E0,00,00,00,00
```





# 原理

左Ctrl和左CapsLock



```
0000 00 00 00 00 00 00 00 00  
0008 03 00 00 00 1D 00 3A 00  
0010 3A 00 1D 00 00 00 00 00  
0018
```



左Ctrl和左a|t

```
00,00,00,00,
00,00,00,00,	-- 固定8个0

03,00,00,00,	-- 表示共更改了3个按键
38,00,1D,00,	-- 前后各4位，分别代表某个按键。
-- 本例为将38,00的按键映射为1D,00。38,00代表Left alt键，1D,00代表Left ctrl键。

1D,00,38,00,	
00,00,00,00		-- 固定8个0

```



左ctrl和左a|t，右ctrl和右a|t

```
00 00 00 00 
00 00 00 00

05 00 00 00 
38 00 1D 00

1D 00 38 00
38 E0 1D E0

1D E0 38 E0
00 00 00 00

```



映射对照表

```
Escape             01 00
Tab          　　　 0F 00
Caps Lock          3A 00
Left Alt           38 00
Left Ctrl          1D 00
Left Shift         2A 00
Left Windows       5B E0
Right Alt          38 E0
Right Ctrl         1D E0
Right Shift        36 00
Right Windows      5C E0
Backspace          0E 00
Delete             53 E0
Enter              1C 00
Space              39 00
Insert             52 E0
HOME               47 E0
End                4F E0
Num Lock           45 00
Page Down          51 E0
Page Up            49 E0
Scroll Lock        46 00
禁用							  00 00
```

