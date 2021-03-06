## ***\*一、背景\****

随着经济的不断发展，越来越多的摩天大楼拔地而起，而电梯作为高层建筑物种的运送人员货物的设备也越来越被广泛使用。电梯的运行是电梯与大楼的各个楼层之间的使用者进行交互的一个过程，对于电梯的模拟，就是对这一交互过程的一个模拟。以本校办公楼为例，有着12层楼，配有两部电梯，在每一层楼中还有着可以呼叫电梯的上下两个按钮。本次课程设计使用C++面向对象的程序设计语言来实现对电梯运行的一个模拟，而面向对象的程序设计方法是将事物抽象为对象，对象有着自己的行为和属性，并通过对消息的反映来完成一定的任务。

## ***\*二、需求\****

功能需求：用面向对象技术来实现单部电梯或者多部电梯的模拟运行软件。电

梯调度策略：顺便服务策略。这种策略在运行控制中所规定的安全前提下，一次将一个方向上的所有呼叫和目标全部完成。然后掉转运行方向完成另外一个方向上的所有呼叫和目标。

任务说明：

要求根据下面的功能说明描述实现模拟电梯控制软件

***\*1． 电梯配置\****

（1） 共有 1 个电梯

（2） 共有 maxfloor 层楼层，这里 maxfloor 暂时取做 9。

（3） 中间层每层有上下两个按钮，最下层只有上行按钮，最上层只有上行按钮。每层都有相应的指示灯，灯亮表示该按钮已经被按下，如果该层的上行或者下行请求已经被响应，则指示灯灭

（4） 电梯内共有 maxfloor 个目标按钮，表示有乘客在该层下电梯。有指示灯指示按钮是否被按下。乘客按按钮导致按钮指示灯亮，如果电已经在该层停靠则该按钮指示灯灭

（5） 另有一启动按钮（GO）。当电梯停在某一楼层后，接受到 GO信息就继续运行。如果得不到 GO 信息，等待一段时间也自动继续运行。

（6） 电梯内设有方向指示灯表示当前电梯运行方向。

***\*2． 电梯的运行控制\****

（1） 电梯的初始状态是电梯位于第一层处，所有按钮都没有按下。

（2） 乘客可以在任意时刻按任何一个目标钮和呼叫钮。呼叫和目标

对应的楼层可能不是电梯当前运行方向可达的楼层。

（3） 如果电梯正在向 I 层驶来，并且位于 I 层与相邻层（向上运行时是 I-1 层或者向下运行时是 I+1 层）之间，则因为安全考虑不响应此时出现的 I 层目标或者请求。如果电梯正好经过了 I 楼层，运行在 I 楼层和下一楼层之间，则为了直接响应此时出现的 I 层目标或者请求，必须至少到达运行方向上的下一楼层然后才能掉头到达 I 楼层（假设掉头无须其额外时间），如果 I 楼层不是刚刚经过的楼层则可以在任意位置掉头，此时

掉头后经过的第一个楼层不可停。

（4） 电梯系统依照某种预先定义好的策略对随机出现的呼叫和目标进行分析和响应。

（5） 乘客数量等外界因素（可能导致停靠时间的长短变化）不予考虑。假设电梯正常运行一层的时间是 5S，停靠目标楼层、上下乘客和电梯继续运行的时间是 5S。

（6） 当电梯停靠某层时，该层的乘客如果错误的按目标或呼叫按钮

都不予响应。

（7） 电梯停要某一层后，苦无目标和呼叫，则电梯处于无方向状态，方向指示灯全灭，否则电梯内某个方向的指示灯亮，表示电梯将向该方向运行。等接到“GO”信号后电梯立即继续运行。若无 GO 信号，则电梯在等了上下乘客和电梯继续运行时间后也将继续运行。

（8） 当一个目标(呼叫)已经被服务后，应将对应的指示灯熄灭。

***\*3． 电梯运行的控制策略\****

顺便服务策略：

顺便服务是一种最常见的简单策略。这种策略在运行控制中所规定的安全前提下，一次将一个方向上的所有呼叫和目标全部完成。然后掉转运行方向完成另外一个方向上的所有呼叫和目标。可以采用设定目标楼层的办法来实现这个策略，即电梯向一个目标楼层运行，但这个楼层可以修改。具体策略如下：

修改目标楼层的策略：

a．如果电梯运行方向向上，那么如果新到一个介于当前电梯所处楼层和目标楼层之间，又可以安全到达的向上呼叫或者目标，将目标楼层修改为这个新的楼层。

b．如果电梯运行方向向下，那么如果新到一个介于当前电梯所处楼层和目标楼层之间，又可以安全到达的向下呼叫或者目标，将目标楼层修改为这个新的楼层。

确定新的目标楼层：

如果电梯向上运行，当它到达某个目标楼层后，则依照以下顺序确定下一个目标楼层：

a．如果比当前层高的楼层有向上呼叫或者目标，那么以最低的高于当前楼层的有向上呼叫或者目标的楼层为目标。

b．如果无法确定目标楼层，那么以最高的向下呼叫或者目标所在楼层为电梯当前目标楼层。

c．如果无法确定目标楼层，那么以最低的向上呼叫所在楼层为电梯当前的目标楼层。

d．如果仍然不能确定目标楼层（此时实际上没有任何呼叫和目标），那么电梯无目标，运行暂停。

如果电梯向下运行，依照以下顺序确定下一目标楼层：

a．如果比当前层低的楼层有向下呼叫或者目标，那么以最高的低于当前楼层的有向下呼叫或者目标的楼层为目标。

b．如果无法确定目标楼层，那么以最低的向上呼叫或者目标所在楼层为电梯当前目标楼层。

c．如果无法确定目标楼层，那么以最高的向下呼叫楼层为目标楼层。

d．如果仍然不能确定目标楼层（此时实际上没有任何呼叫和目标），那么电梯无目标，运行暂停。

 

## ***\*模拟电梯的功能\****

根据实际功能分析，模拟电梯具有复杂的状态和交互作用，众多的事件将引起状态的复杂变化。电梯状态如下：电梯向上运行状态、电梯向下运行状态、电梯停止状态。 定义为int run_status1向上，2向下,0停止。按钮有分成两种一种是电梯外的请求电梯赶来的按钮，另外一种则是电梯内发出所要到达楼层的按钮。

基于以上的分析，把电梯的状态做出如下说明。

（1）电梯初始时刻在一层最初始的运行方向只可能是向上走。

（2）电梯启动后不管现在所在是第几层，电梯所要做的就是根据自己目前的运行方向往上查询是否有电梯外楼层所发出的请求，而对于向下运行方向的请求先不去理会，保存起来。

（3）电梯的请求有两种，电梯外所在楼层发出的要电梯赶来的请求和电梯内发出的所要到达楼层的请求，这也正好与电梯系统的两种按钮所对应。假设电梯正在往4楼向上运行，此时电梯要查询4楼以上的楼层是否还有人要上楼或者下楼，若没有人要上楼或下楼，则要查询4楼以下是否有人要上下楼，如果有则应该改变电梯运行方向，向下运行去接4楼下发出请求的那一个乘客。

（4）对于这两种请求，可以使用两个数组来储存。使用数组储存的原因是因为，大楼和数组有着相识的特点，都是连续的，这样就可以使用数组的下标来表示大楼的楼层。

A.对于第一种请求电梯外所在楼层所发出的请求 定义为int eout[10]，最开始初始化为0。若eout[i]=1表示第i层有乘客发出了一个向上的请求，若eout[i]=2表示第i层有乘客发出了一个向下的请求，若eout[i]=3表示第i层既有乘客发出一个向下运行的请求，又有乘客发出了一个向上运行的请求。这里我们也可以联系实际，在电梯还没有到发出请求的楼层接乘客时，是没有办法知道到底有多少个乘客要上电梯的，只有乘客进入电梯之后才知道。

B.对于第二种请求电梯内发出的所要到达楼层的请求， 定义为int floor[10]，最开始初始化为0。若floor[i]=1表示到达第i层时，有乘客到达了目的楼层，需要下电梯。

（5）对应的内部电梯按钮，按下后就会调用相对应的set_floor函数把对应的数组元素修改为1。对于上下按钮，按下后调用对应的set_out函数，若是向上把对应的数组元素修改为1，若是向下把对应的数组元素修改为2，若是既有向上又有向下把对应的数组元素修改为3。

（6）按照两种请求的不同，将两种按钮依照电梯内输入和电梯外输入封装为两个函数 ：电梯内输入void inoperate(int i)，电梯外输入void outoperate()。

具体内容参照博客：https://www.cnblogs.com/wkfvawl/p/11379220.html
