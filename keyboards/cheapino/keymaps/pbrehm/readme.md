took miryoku default layout from 
https://github.com/manna-harbour/miryoku/blob/master/data/configurator/miryoku-configurator-crkbd.json

then modified layout section and deleted extra column which was not used.

then remapped letters to qwerty
as a result, I switched :; to '" on layer 4 and 5
then I moved arrows to hjkl instead of jkl;
also moved mouse emulation to hjkl and mouse wheel emulation to nm,.

to compile do
qmk compile -kb cheapino -km pbrehm

flash with 
qmk flash -kb cheapino -km pbrehm
