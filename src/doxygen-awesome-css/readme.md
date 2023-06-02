# Doxygen Awesome

[Doxygen Awesome](https://github.com/jothepro/doxygen-awesome-css) is a great project to make doxygen look
nicer.

We copied the css right from that repo, however we had to do a change and comment out line 1716
(`display:inline-block`) because of a display glitch with needs.

```css
/*
 Table
 */

.contents table:not(.memberdecls):not(.mlabels):not(.fieldtable):not(.memname),
.contents table:not(.memberdecls):not(.mlabels):not(.fieldtable):not(.memname) tbody {
    /* display: inline-block; */
    max-width: 100%;
}
```
