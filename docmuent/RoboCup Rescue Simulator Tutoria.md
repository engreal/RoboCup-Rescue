### RoboCup Rescue Simulator Tutorial / “机器人足球世界杯”救援模拟器教程
<div style="text-align:right">孙想想 译</div>

#### 1 Introduction / 介绍
A disater may be defined as a crisis situation causing widespreas human, material, economical and enverionment damages that surpasses the system's capacity to recover.
灾难是一种在人员、财物、经济、环境等方面造成了超过系统恢复能力的损害的危机状况。
There are two main ways of treating a disater:
主要有两种应对方法：
1. Preventing it from happening, which can be through identifying its causes and preventing them tasking place.
防患于未然，通过识别灾难发生的原因预先阻止其发生。
2. Managing its impacts once they happen through the application of previously established governmental policies and strategies.
一旦灾难发生，通过执行先前建立的政策和战略控制灾难造成额度影响。

The former option is unually more desirable, since it is very effective and very little disrupting. However, this is not always possible, since some events are too intense to be avoided even if forecasted with great antecedence, and other are unpredictable. Thus, the management option becomes necessary for the mitigation of the disaster's impacts.
前者更可取，因为它非常有效并且不会被轻易干扰。然而，这并非总是可行的，因为有些事件过于强大，即使有充分的预测也不能避免，而有些事是不可预测的。因此，选择控制灾难以减轻影响是有必要的。
After the 1995 Kobe earthquake events, Japanese researchers came up with the idea of developing a simulator that reproduces conditions similar to a urban postearthquake in order to test mitigation strategies for this kind of disaster. They also organized a competition, the RoboCup Rescue Agent Simulation League, in which people from all over the world would be able to demonstrate their advancements in the coordination of rescuing agents teams running in this simulator and to help in the development of policies and strategies to mitigate the impact of such disasters.
在1995年神户地震后，日本研究人员产生了开发模拟器的想法，这种模拟器可以重现类似城市地震后的情况，从而测试应对这类灾难的策略。他们还组织了"the RoboCup Rescue Agent Simulation League"竞赛，世界各地的人们可以在这个模拟器中展示他们在协调救援队伍方面的进展，并帮助制定政策和战略以减轻灾害的影响。
The objective of this document is facilitate the first contact with the RoboCup Rescue Agent simulator and streamline the learning curve for new comers. This document is based on the 2011 version (rescue-1.0a-2011). Spite of being targeted for people interested in participating in RoboCup Rescue Agent competitions, hopefully it may also help people interested in using it for disaster management research purposes.
这份文档旨在帮助第一次接“触救援组”模拟器的人学习使用它。文档是基于2011年的版本(rescue-1.0a-2011)。尽管是给有兴趣参加机器人世界杯的人们使用的，我们希望它能帮助有意使用它进行灾难管理研究的人们。

#### 2 Installing and Running / 安装并运行
This tutorial assumes you will run the simulator in a Linux machine spite of being possible to use it in Microsoft Windows. However, our recommendation is for Linux because they are free and most of the distributions have a good supportive users community. If you have never used Linux before and intend to, we recommend starting with a user-friendly distribution, such as Ubuntu or Fedora . The Linux distribution used to write this tutorial was Ubuntu Linux 12.04 LTS。
尽管Windows和macOS也可以运行仿真服务器和代理，本手册假设它们是在Linux平台运行的。因为Linux是开源的，并且大多数发行版都有支持很好的用户社区，所以我们建议使用Linux。如果你之前从未使用过Linux，我们建议使用对初学者友好的发行版，比如Ubuntu和Fedora。用于编写本手册的Linux发行版是Ubuntu Linux 12.04 LTS。

##### 2.1 Required Software / 依赖的软件
In addition to Linux, you will need the following software installed to compile and run the simulator:
除了Linux之外，您还需要安装了以下软件来编译和运行模拟器：
* Java JDK 1.6 or higher (Oracle or OpenJDK);
* ant 1.8 or higher;
* rng-tools (not strictly necessary, but strongly recommended as it will allow a much faster connection of the agents with the simulator).

If you are using Ubuntu, all of these software are present in the default software repositories, except for the Oracle JDK. In order to install OpenJDK, ant and rng-tools, open a terminal window and type (certify that you computer is connected to the Internet).
如果您正在使用Ubuntu，除了Oracle JDK，所有软件都存在默认的软件存储库中。打开终端输入以下命令来安装OpenJDK,ant和rng工具(确认计算机已联网)：
```sh
sudo apt-get install openjdk-7-jdk ant rng-tools
```
and enter your user password when asked to. It is recommendable, however, to use the Oracle JDK version; a guide with instructions for its installation can be found at http://www.webupd8.org/2012/01/install-oracle-java-jdk-7-in-ubuntu-via.html
当被询问时输入用户密码。推荐使用Oracle JDK，安装指可以在http://www.webupd8.org/2012/01/install-oracle-java-jdk-7-in-ubuntu-via.html上找到。

##### 2.2 Installing / 安装
1. Download the simulator file (rescue-1.0a-2011) at the RoboCup Rescue sourceforge project website http://sourceforge.net/projects/roborescue/
files/.
在sourceforge网站上下载RoboCup Rescue项目的模拟器文件。
2. Extract the content of the file you have just downloaded in to a directory, for instance your home folder (the one that has the same name as your user name).
将刚刚下载的文件的内容提取到一个目录中，例如你的家目录(和用户名同名的目录)。
3. Open a terminal window, change directory to the folder created by the extractor (this can be done by typing cd rescue-1.0a-2011), and enter the command:
打开终端，切换目录至提取器创建的目录(也可以键入cd rescue-1.0a-2011)，然后输入命令：
```shell
ant
```
This will compile the simulator.
这将编译模拟器。
4. In your terminal, enter the command.
在终端输入命令。
```shell
sudo gedit /etc/defaults/rng-tools
```
Enter your user password and a text file will be opened. Type the line anywhere in the file and close it, saving the changes made.
输入用户密码后会打开一个文件。在文件的任意位置输入以下内容，保存修改内容后关闭文件。
```
HRNGDEVICE=/dev/urandom
```
Then enter the command in your terminal to start the rng daemon.
接着在终端输入命令启动rng。

5. Change directory to the simulator' s folder and then to boot directory; edit the start.sh file by replacing the lines according follows
```
startKernel
startSims
```
by the lines
```
startKernel --nomenu
startSims --nogui
```
The simulator is now installed and good to go!
切换目录至模拟器所在的文件夹，进入boot目录，编辑修改下面的两行。
模拟器现在安装好了！

##### 2.3 Directories / 目录结构
Important directories of the simulator are:
模拟器的关键目录如下：
* boot/: scripts of execution of the simulator
模拟器的启动脚本。
* boot/config/: configuration files of the simulator.
模拟器的配置文件。
* boot/logs/: log files.
日志文件。
* build/: the simulator’s Java classes.
模拟器的JAVA类。
* docs/: javadoc documentation of the simulator.
模拟器的javadoc 文档。
* jars/: the simulator’s JAR files.
模拟器的jar文件。
* lib/: libraries used by the simulator.
模拟器使用的库。
* maps/: maps that can be ran in the simulator .
可以在模拟器中运行的地图。
* modules/: the simulator’s source code.
模拟器的源代码。
* oldsims/: source code of some of the simulator’s older versions.
一些旧版模拟器的源代码。

##### 2.4 Running / 运行
To run the simulator, you must open the terminal, move to the boot folder inside the simulator’s folder and type the following command：
运行模拟器需要：打开终端，切换目录至模拟器所在的文件夹，进入boot目录，输入以下命令：
```shell
./start.sh [OPTIONS]
```
Where [OPTIONS] are optional parameters that can be one or all of the following:
[OPTIONS]是可选参数，可以是以下的一个或全部:
* -m MAPDIR, where MAPDIR is the path to the folder containing the map you want to run (default is ../maps/gml/test).
MAPDIR是你想要运行地图所在的目录（默认为"../maps/gml/test"）。
* -l LOGDIR [LABEL OPTIONS], where LOGDIR is the folder where the log files will be stored (default is /logs). LABEL OPTIONS are the following:
LOGDIR是储存日志文件的目录。(默认为"/logs")。[LABEL OPTIONS]选项如下:
	* -s, to store the log archives in a folder named with the time and date of the simulation inside LOGDIR.
	将日志档案存储在LOGDIR目录下一个由模拟器的日期和时间命名的文件夹中。
* -t TEAMNAME, where TEAMNAME is the name of the team to appear in the name of the folder created by -s (default is none).
TEAMNAME是团队名称,它会被用于构成"-s"创建文件夹的名称。
** NOTE: The simulator does not work if -l and its options are used.
注意：如果使用"-l"及相关选项，模拟器不会工作。
**

An example of a run command would be:
一个运行命令的例子是：
```shell
./start.sh -m ../maps/gml/berlin
```
You will get as a result something as depicted in Figure 1.
您将得到如图1所示的结果。
![](f1.png)
Next, you must launch the agents that will control the entities in the simulator. For an initial test, use the the agents provided by the simulator itself. Then, open a new terminal window, move to the boot folder inside the simulator’s folder and type the command：
接着，你必须启动控制模拟器中实例的代理。初始测试可以使用模拟器自带的代理。然后，打开一个新的终端，切换目录至模拟器所在的文件夹，进入boot目录，输入以下命令：
```shell
./sampleagents.sh
```
Now just hit the Run button in the Kernel GUI and the simulator will start. To terminate the execution of the simulator or the agents' script, select the terminal window and press Ctrl-C.
现在点击内核GUI中的Run按钮，模拟器就会启动。要终止模拟器或代理脚本的执行，请选择终端窗口并按"Ctrl-C"。

#### 3 Simulator Architecture / 模拟器的体系结构
The simulator is in fact divided into many other simulators:
模拟器实际上被分为许多其他模拟器：
*  the clear simulator, responsible for blockade removal.
clear simulator 负责清除障碍。
* the collapse simulator, responsible for managing buildings' structural damage and blockade creation.
collapse simulator 管理建筑物的结构损坏和产生障碍。
* the fire simulator, responsible for the fire spread between buildings.
fire simulator 控制建筑物之间的火势蔓延。
*  the traffic simulator, responsible for humans'  movement.
traffic simulator 模拟人类的活动。
* the misc simulator, responsible for human damage and buriedness.
misc simulator 模拟人类的伤亡。

These simulators establish connections to the kernel simulator, responsible for coordinating the simulators’ processes and centralizing the data they generate.
这些模拟器建立与内核模拟器的连接，协调模拟器的进程，并将它们生成的数据集中起来。
![](f2.png)
The RoboCup Rescue simulator was designed to create a partially observable, discrete-time, dynamic, stochastic, multiagent environment. In other words, in this environment:
RoboCup Rescue模拟器的设计是为了创建一个部分可观察的、离散的、动态的、随机的、多主体的环境。换句话说，在这种环境下:
* the complete world current state cannot be known through a single agent’sperception (even if the agent has an infinite range of sight, it still will not be able to see through a building’s walls);
不能通过单独的一个代理了解世界完整状况（即使代理有无限的视野，它仍然不能无视建筑物的墙壁）
* time is divided in intervals, as opposed to continuous time;
时间按时间间隔划分，而不是连续时间段
* there are random elements that affect its state transition;
有随机因素影响状态变化;
* there is more than one agent present,  and one's actions may interfere with the others' performance.
有多个代理在场，某一个的行为可能会妨碍其他代理的表现。

Time is divided in time-steps; during each time-step, the agent perceives the environment and reasons about what action it will perform. In each time-step, the following happens:
时间被分成时间周期;在每一个时间周期内，代理会确认环境以及它将执行的操作的原因。在每一个时间周期中，会执行以下事件:
1. The kernel updates all agents' perception (visual and communication) and waits for the agents' commands.
工作内核更新所有代理的感知(视觉和通信)，并等待代理的命令。
2. The agents updates their world model and make their decisions, sending their commands to the kernel.
代理更新他们的世界模型并做出他们的决定，向内核发送他们的命令。
3. The kernel sends the agents’ commands to the simulators.
内核将代理的命令发送给模拟器。
4. The simulators process the agents’ commands and send the changes suffered by the environment back to the kernel.
模拟器处理代理的命令，并将环境发生的变化回传给内核。
5. The kernel sends the environment changes to the viewers.
内核向监察器发送环境变更信息。


#### 4 Simulator Entities / 模拟器实例
Several objects are represented in the simulator as depicted in Figure 3.
在模拟器中有几个对象，如图3所示。
![](f3.png)

##### 4.1 Blockades / 障碍
Blockades obstruct the path of agents and civilians; they are represented as black polygons in roads. Blockades appear in the beginning of the simulation and are not produced after this. They must be removed by Police Forces.
障碍阻塞了特工和市民的道路，它们被描绘成道路上的黑色多边形。障碍在模拟开始的时候出现，此后将不会产生。必须由警察清理它们。

**Properties / 属性**
* position: ID of the road to which the blockade belongs
障碍所在道路的ID
* repair cost: cost to completely remove the blockade from the road
清楚道路全部障碍的成本
* shape: a rectangle which surrounds the whole blockade
包围障碍的矩形
* X & Y: coordinates of the blockade’s centroid
障碍中心的坐标
* apexes: vector containing the apexes of the blockade
包含障碍顶点的矢量

##### 4.2 Area / 区域
Area entities represent buildings and roads.
区域实体代表建筑物和道路。

**Properties / 属性**
* blockades: a list with the blockades in that area
该区域障碍的列表
* edges: a list with the edges that limit the area
该区域边界线的列表
* neighbours: a list of the areas that can be accessed from this area
该区域相邻区域的列表
* X & Y: coordinates representing the area in the map
该区域在地图上的坐标

While both buildings and roads have the blockades attribute, blockades appear only in roads.
虽然建筑物和道路都有障碍属性，但障碍只出现在道路上。

###### 4.2.1 Buildings 建筑物
Buildings group includes all kinds of buildings in the simulator: besides the regular ones, described below, there are special kinds of buildings (refuges, ambulance centres, fire stations and police offces, shown in Figure 4) which cannot catch on fire. They will be described in later sections of this document.
建筑物包括模拟器中的各种建筑：除了常规的建筑外，还有不能着火的特殊建筑（避难所，救护中心，消防站和警察局），如图4所示。它们将在本文档后面的部分中进行描述。
![](f4.png)
**Properties / 属性**
* brokenness: how structurally damaged the building is; does not change during the simulation.
表示建筑物的结构损坏程度，在模拟过程中不会发生变化。
* fieryness: the intensity of the fire and fire-related damage in the building。
建筑物内的火势和火灾造成的破坏程度。
	* UNBURNT (not burnt at all) 未燃烧
	* WATER DAMAGE (not burnt at all, but has water damage) 不再烧毁，但是水造成了损坏
	* HEATING (on fire a bit) 火势小
	* BURNING (on fire a bit more) 火势一般
	* INFERNO (on fire a lot) 火势很大
	* MINOR DAMAGE (extinguished but minor damage) 轻微损坏
	* MODERATE DAMAGE (extinguished but moderate damage) 中度损坏
	* SEVERE DAMAGE (extinguished but major damage)
	* BURNT OUT (completely burnt out) 完全烧坏
* floors: the number of floors the building has.
建筑物的楼层数
* ignition: indicates if the simulator has lit this building on fire.
表示模拟器是否点燃了这座建筑。
* importance: (unknown function; has equal values to all buildings).
未知函数，所有建筑物都有相同的值。
* temperature: temperature of the building; if it crosses a certain threshold, the building catches on fir.
建筑物的温度，当它超过阈值的时候，建筑物着火。
* ground area: the area of each floor.
每层的面积。
* total area: the total area of the building (floors * ground area).
建筑物的总面积。

Regular buildings are represented as polygons of various colors, depending of their status, as shown in Figure 5; the darker the color, the greater the structural fire or water damage.
普通建筑物用各种颜色的多边形表示，颜色视其状态而定，如图5所示;颜色越深，建筑物受到损毁越大。
![](f5.png)
In the beginning of the simulation, broken buildings trap humans inside it under debris; these debris must be removed by Ambulance Teams, who then proceeds to rescue the human.
在模拟的开始，毁坏的建筑物将人困在废墟下。救援队必须移除建筑物碎片来营救人员。
A refuge is a special kind of building: it represents a place destined to support the rescue activity, providing medical care for the wounded and water to the Fire Brigades. In the simulator, humans inside a refuge have their damage zeroed, which means they do not lose health while they stay there; damage will, however, resume when the human entity leaves the refuge. Also, Fire Brigades have their water supply replenished by a certain amount during each cycle while they are inside the refuge.
避难所是一种特殊的建筑：它代表了一个支持救援活动的地方，为伤员提供医疗护理，并向消防队提供水。在模拟器中，人类在避难所时，伤害会被归零，这意味着他们在那里的时候生命值不会降低。当人离开避难所时，伤害就会复原。消防队在进入避难所之后，每个周期内都会补给一定数量水。

###### 4.2.2 Roads / 道路
Area entities representing roads have no new attributes besides those of area entities.
除区域实体原有的属性外，代表道路的区域实体没有新的属性。

##### 4.3 Humans / 人类
These are the entities representing humans. In the simulator, they can be Civilians, Ambulance Teams, Fire Brigades or Police Forces. They are all represented by circles of different colors, and cannot move by themselves if they are dead or buried.
这些是代表人类的实体。在模拟器中，他们可以是平民，救护队，消防队或警察部队。他们都是由不同颜色的圆圈表示，他们如果死了或被掩埋了，就不能自己移动。


**Properties / 属性**
* buriedness: how deep the human is buried
人类被掩埋的深度
* damage: how much HP the human loses per cycle; zeroes when a refuge is reached.
人在每个循环中损失多少生命值，当到达避难所时被置零。
* direction: direction to where the human is moving (inferred); the Y-axis positive half is zero, and the value increases until 129599 (360*60*60 - 1) seconds anti-clockwise.
人类移动的方向。y轴正半轴为零，数值逆时针增加到129599(360 *60*60 - 1)秒。
* HP: health points of the human; if it reaches 0, the human dies.
人类的生命值。如果它达到0，人类就死了。
* position: ID of the entity where the human is; may be an area entity or a human entity (if it is inside an ambulance).
人所处实体的ID;可能是一个区域或一个人(如果在救护车内)。
* position history: a list of the entities the human has passed during the last cycle, in chronological order.
在上一个周期中人类通过的实体列表，按时间顺序排列。
* stamina: not implemented; would decrease each time the agent took an action and would be partially replenished at the beginning of each cycle.
没有实现。每次代理采取行动时，耐力都会减少，并在每个周期的开始得到部分补充。
* travel distance: (unknown).
未知。
* X & Y: coordinates representing the human in the map.
代表人类在地图中的坐标。

The color of each human in the simulator is defined by its type and its health: the lower its health, the darker it is. Dead humans are represented by the black color.
模拟器中每个人的颜色都取决于他的类型和健康:健康越低，颜色越深。死人用黑色表示。

###### 4.3.1 Civilians / 市民
Civilians are human entities and they are not part of a rescue team; they are represented by the color green. Their standard behaviour is to walk to the closest refuge on their on if they are not wounded or buried; otherwise, they will have to be transported by an Ambulance Team.
市民是人的实例，他们不是救援队伍的一部分。市民用绿色表示，他们的标准行为是：如果没有受伤或被掩埋，就走到最近的避难所；否则，他们就只能被救护车运走。

#### 5 Simulator Agents / 模拟器代理
These are the entities that will compose your rescue team; in other words, this is what you will program. Agents are divided in two types: platoon agents and central agents.
这些是组成你的救援队的实体;换句话说，这就是你要编写的程序。代理分为两类:排代理和中央代理。

##### 5.1 Platoon agents / 排代理
Platoon agents are able to interact with the simulated environment through perception and executing actions on it. They can also exchange messages with other agents by vocal or radio communication. They are comprised of three different categories: the Ambulance Team, Fire Brigade and Police Force.
排代理能够通过感知和执行动作与模拟环境进行交互。他们还可以通过声音和无线电通信与其他代理交换信息。它们由三个组成不同类别:救护队、消防队和警察队。

###### 5.1.1 Ambulance Team / 救护车队
Ambulance Teams are responsible for rescuing humans (agents and civilians) and take them to a refuge. They are able to unbury victims and carry one person.
救护车队负责营救人类(特工和市民)，并将他们送往避难所。他们能够挖掘受难者并携带一个人。

###### 5.1.2 Fire Brigade / 消防队
Fire brigades are responsible for extinguish fires on buildings. Moreover, they carry a certain amount of water in their tanks and they can replenish it in a refuge.
消防队负责扑灭建筑物上的大火。此外，他们在自带的水箱里携带一定量的水，可以在避难所中补充水。

###### 5.1.3 Police Force / 警察部队
Police forces are responsible for removing blockades from the roads. When ordered to do so, they will clean a certain amount, specified in the repair cost parameter, from the target blockade at each cycle. However, differently from Ambulance Teams and Fire Brigades, having two Police Forces acting on the same blockade brings no advantage to the process: it will be as though there was only one Police Force acting on it.
警察部队负责清除道路上的障碍。被命令清障后，他们将在每个时钟周期内根据成本参数清理一定数量的障碍。不同于救护队和消防队，让两名警察在同样的封锁线上行动对这个过程毫无益处，相当于只有一个警察在行动。

##### 5.2 Central agents / 中央代理
Central agents are a type of agents whose only interaction with the world is through radio communication. There are three types of central agents: Ambulance Centers, Fire Stations and Police Offices, and they are represented as buildings.
中央代理是一种通过无线电通信与世界交互的代理。有三种类型的中央代理:救护中心、消防站和警察办公室，它们都是建筑物。

#### 6 Agents Perceptions and Commands / 代理的感知识和命令
The simulator has two perception modes: standard and line of sight. We will discuss just the latter, since it is the one used in competitions.
模拟器有两种感知模式：标准和视线。我们将只讨论后者，因为它是用于比赛的。
Line of sight perception simulates visual perception of the agent: a vision range and a number of rays are defined and the agent percepts anything that is reached by these rays.
视线模拟了特工的视觉感知：定义了可视范围和许多射线，射线能抵达的地方构成特工的可视范围。
![](f6.png)
The set of currently visible entities for an agent is stored in a structure named ChangeSet; entities present in it are automatically updated in its world model; that is, if an agent perceives a blockade it did not know that was there before, this blockade is automatically added to its world model. The opposite, though does not happen: if the agent does not perceive a blockade any more, nothing in its world model changes, even if it knew that there was a blockade there before. In that case, the agent will still think that there is a blockade in that road, even though such blockade has already been cleared. Thus, it is up to the agent to figure this out and modify its world model accordingly.
代理目前可见的食物设置存储在一个名为ChangeSet结构中，该结构中记录的事物
会在世界模型中自动同步。也就是说，如果一个特工看到了之前没见过的障碍，这个障碍会被自动同步到世界模型中。相反，如果一个特工无法再看到某个障碍（这种情况不应该发生），即使他知道之前哪里存在障碍，世界模型也不会因此发生变化。在这种情况下，即使障碍已经被清除了，特工仍然认为这条路上有一个障碍。因此，这个问题要由特工解决，并相应地调整世界模型。

#### 7 Communication / 通讯
There are two forms of communication available in the simulator: direct communication and radio communication. Direct communication, done with the command speak, is communication audible to humans within a radius from the emitter agent, as if the emitter shouted something.
模拟器中有两种通信方式：直接通信和无线电通信。直接通信由speak命令触发，可以和在说话特工的半径范围内的人类通信，就好像说话的特工在发出声音一样。
Radio communication is done with the command tell, and transmits information to all agents that are signed up to the channel on which it was broadcasted. Radio communication channels are present in limited number, each one with a limited bandwidth.
无线通信由tell命令触发，它将信息发送给所有在其广播频道上注册的特工。无线通信的信道数量有限，每一个信道的带宽有限。
In both types of communication, the message has to be coded into a string of bytes before being sent; the receptor must decode it once it receives the message. Both types might be susceptible to message drop out, where the message is not received by its targets; radio communication is also susceptible to message failure, where the message is received empty.
无论是哪种通信方式，消息必须在发送之前进行编码。消息的接收者需要对消息进行解码。如果消息没有被目标接收，两种通信方式都有可能中断。无线通信在接收消息为空时也会发生错误。

#### 8 Tios for programming the rescue team / 编写救援队的技巧
We advise to start a Rescue Team by copying and modifying the sample agents provided with the simulator. The programming language used is Java and there are several IDEs availables, the most popular are Eclipse and NetBeans. This section will be described the use of Eclipse.
我们建议通过复制和修改模拟器提供的示例代码来组建一支救援队。编程语言用的是Java，有很多可用的ide，其中最受欢迎的是Eclipse和Netbeans。本节将描述Eclipse的使用。

##### 8.1 Beginning a project / 开始一个项目
After installing Eclipse, you should create a project for developing your rescue team: click on File > New... > Java Project; name your project and click on Next >.
在安装Eclipse之后，您应该创建一个项目来开发您的救援队。依次单击“File”、“New”……“JavaProject”，输入你的项目名称，单击“Next”。
Select the ”Libraries” tab and add all the content from the jars and the lib folders using the Add external JARs... button, as shown in figure 7, and click ”Finish”.
如如图7所示，选择 ”Libraries”，然后使用“Add external JARs...”键把jars和lib文件下的所有内容添加到项目依赖。
![](f7.png)
You now have a project, in which you can create and edit Java classes. Let us now copy the source code of the sample agents into it: opening the simulator folder and copy the contents of the modules/sample/src folder to the src folder of your project. Go back to Eclipse and refresh the project.
现在有了一个项目，你可以在其中创建和编辑Java类。现在把示例代理的源代码复制到项目中：打开模拟器的文件夹，把modules/sample/src里面的所有内容复制到你的项目的src目录下。返回到Eclipse并刷新项目。
Start the simulator, but do not launch any agents; instead, right click on the LaunchSampleAgents class inside your Eclipse project and chose the option "Run As > Run Configurations..." . A new window will be opened; double click the "Java Application" icon, and press "Run". Doing this, you have just launched your project' s agents through Eclipse; once the simulation ends, terminate the application by clicking on the red button on the Console tab.
启动模拟器，但不要启动任何代理。右键单击Eclipse项目中的LaunchSampleAgents类，选择”Run As“、”Run Configurations...“。会弹出一个窗口，双击”Java Applications“图标，单击”Run“。这样，你就通过Eclipse启动了代理。模拟结束后，单击控制台选项卡上的红色按钮终止应用程序。
![](f8.png)
With this project, you can look into the source code of the sample agents, make modifications in it and observe the behaviour changes that arise from them.
在这个项目里，你可以查看示例代理的源代码。也可以修改源码，然后观察修改造成的行为变化。

##### 8.2 Basic contents / 基本内容
Now that the the project is up, let us take a look at some of the contents:
现在项目完成了，让我们看一下其中的一些内容:

###### 8.2.1 AbstractSampleAgent / 抽象代理类
There is an abstract class called AbstractSampleAgent, which contains methods and attributes that all platoon agents must have: for example, its developers thought it would be good if each agent had lists with all the buildings and roads of the map for quick access instead of retrieving them from the world model every time they were needed, so they created the buildingIDs and roadIDs attributes.
AbstractSampleAgent是一个抽象类，它定义了所有代理必须具备的方法和属性：例如，开发者认为，每个代理都具备一个可以快速查询的建筑物和道路列表要比每次都在世界模型中检索高效，那么开发者就会创建buildingIDS属性和roadIDs属性。
The postConnect method must prepare the agents for the simulation: the agents are already connected to the simulator and their world model has been created. That means they can get information from it to start their attributes, such as the buildingIDs list.
”postConnect“方法必须为模拟器做好代理的准备：代理已经连接到模拟器，他们的世界模型也已经被创造出来了。这意味着他们可以从模拟器获得信息来初始化他们的属性，如buildingIDs列表。

###### 8.2.2 Agent classes / 代理类
Programming a rescue team revolves around developing the think method: this is a method all platoon and central agents must implement, and will determine the reasoning the agent does and the actions it takes during each time-step. Looking into the agent classes (SampleAmbulanceTeam, SampleFireBrigade, SamplePoliceForce), one can see how its behaviour was modelled.
救援队的编程核心是着改进“think”方法：这是一个所有代理必须实现的方法，它决定代理在每个时钟周期中执行的判断和动作。在代理类中可以看到其行为是怎样建模的。
The agents can issue the following commands to the simulator:
代理可以向模拟器发送以下命令：
* Communication commands:
通信命令：
	* Say: the agent issues a message through direct communication;
	代理通过直接通信发送信息；
	* Tell: the agent broadcasts a message through radio communication;
	代理通过无线通信发送信息；
* Action commands:
行动命令：
	* Move: the agent moves through a determined path;
	代理沿指定路径移动；
	* Rest: the agents takes no action;
	代理停止行动。
	* Rescue: the agent unburies a victim by a certain amount (exclusive to ambulance teams);
	代理救出一定数量的受灾者（救护车独有）；
	* Load: the agent picks up a victim (exclusive to ambulance teams);
	代理收集受灾者（救护车独有）；
	* Unload: the agent unloads a victim he is currently carrying (exclusive to ambulance teams);
	代理放下受灾者（救护车独有）；
	* Extinguish: the agent directs a certain amount of water to a building (exclusive to fire brigades);
	代理将一定量的水导入建筑物（消防队独有）；
	* Clear: the agent removes a certain amount of debris from a blockade (exclusive to police forces).
	代理清理部分障碍（警察独有）。

During a time-step, an agent can issue both communication commands and one action command.
在每一个时钟周期内，代理可以发送多个通信命令和一个动作命令。

##### 8.3 Tinkering the rescue team / 修改救援队
Now that you have a template of how a rescue team is programmed, you can start modifying it to learn about the simulator and create your own team. Think of what could be modified to increase the team’s performance, make changes and observe the results.
现在你已经有了一个编写救援团队的模板，你可以开始修改它来了解模拟器，也可以创建你自己的救援队。思考可以修改什么来增加救援队的性能，做出改变并观察结果。
Also, since communication is not implemented in the sample agents, a good way of observing its functioning is using the RoboCup Rescue Simulation Communication Library (RCRSCS), developed by the SUNTORI team. A manual for using this library was added as an appendix at the end of this document.
示例代理中并没有实现通信功能，你可以使用由SUNTORI团队开发的RoboCup救援模拟通信库(RCRSCS)实现通信功能。本文档末尾添加了使用该库的手册。

Some final tips worth mentioning are:
最后一些值得一提的建议：
* An agent’s world model will be automatically modified if it perceives (i.e.sees) something new; it will not change to account that something has gone missing.
如果一个代理感知到一些新的东西，它的世界模型就会被自动更新。它不会因为某些东西消失了而改变。
* You can obtain a list of all the entities an agent is currently perceiving using the ChangeSet class passed on the think method.
你可以向think方法传递ChangeSet类的参数，一次获取一个代理目前看到的所有事物的列表。
* Any command issued by an agent, granted that it has acceptable arguments, will be executed by the simulator even if it has no effect on the world; the extinguish command, for instance, has no effect if Fire Brigade that issues it * does not carry an enough quantity of water.
任何一个代理发出的命令，只要它有合法的参数，就会被模拟器执行，即使它对世界没有影响。例如，灭火队在没有水的情况下发出的灭火命令，那么灭火指令就没有作用。
* Be aware that at each cycle the simulator executes only one action, except the communication actions, for each agent. Thus, if multiple actions are sent to the simulator by an agent, only the last one is actually executed.
注意，在每个时钟周期内，除了通信操作，对于每个代理模拟器只执行一个动作。因此，如果一个代理将多个动作命令发送到模拟器，则只有最后一个动作会被实际执行。

**Good luck！**

### Appendices / 附录
#### RoboCup Rescue Simulator Communication Library (RCRSCS) / 机器人杯救援模拟器通信库
##### 1 Introduction / 简介
The RoboCup Rescue Agent Simulator is a discrete-time distributed simulation system and it aims to provide a simulation to reproduce conditions that arise after the occurrence of an earthquake in an urban area. In order to make the simulation more realistic, some issues are considered, such as heterogeneity (different types of rescue agents), dynamic environment (fires spread; injured victims), limited information (agents can only see a short distance), uncertain information (agents do not see the true state of the world), limited communication (messages can be dropped or have noise) and limited processing time (agents have a limited time to issue commands). It is thus characterized as a complex multiagent domain.
机器人杯救援模拟器是一个离散时间分布的仿真系统，它的目标是通过仿真模拟来重现城市地区在地震发生后出现的情况。为了使模拟更加现实，需要考虑一些问题，比如异质性(不同类型的救援人员)，动态环境(火灾蔓延、受伤的受灾者)，有限的信息(代理只能看到有限的距离)，不确定的信息(代理没有看到世界的真实状态)，有限的通信(消息可能丢失或有噪声)和有限的处理时间(代理只有有限的时间发出命令)。因此，它是一个复杂的多智能体域。
![](f9.png)
The architecture of the RoboCup Rescue Agent simulator is comprised of one kernel, one viewer, domain objects represented in the city map, some sub-simulators, each assigned to a specific task within the simulation, and some agents responsible to carry out tasks on the environment in order to mitigate the disaster impact . There are sub-simulators responsible for fire simulation, traffic simulation, collapse simulation, blockage simulation and one responsible for miscellaneous simulations, such as humans’ damage and buriedness and road clearing times. Each sub-simulator runs as an independent process, being the simulator kernel responsible for managing the interaction among them through the network. This setting allows for the computational load to be distributed among several computers, which helps the simulation workload distribution.
RoboCup救援代理模拟器的体系结构包括一个内核、一个监视器、在城市地图中表示的区域对象、一些被分配特定模拟任务的子模拟器、一些负责执行环境方面的任务，以减轻灾害影响的一些代理。子模拟器分别负责火灾模拟、交通模拟、塌方模拟、阻塞模拟，还有负责模拟其他项目的，比如人类受伤、被掩埋、道路清理。每个子模拟器都是独立的进程，模拟器的核心负责通过网络管理它们之间的通信。此设置允许把计算任务分配在多台计算机中，这有助于分配工作量。
In order to perform their tasks, the agents are allowed to exchange messages among themselves through communication channels. The simulator allows the agents to use two types of messages: tell and say. In order to use the tell message type, the agent must be subscribed to a channel and when it sends a tell message through this channel, the content is broadcast via radio to all the platoon agents subscribed to it. On the other hand, the say message type limits its receivers to all the agents located within a predefined radius from the sender.
为了执行任务，代理可以通过信道互相交换消息。模拟器允许代理使用两类信息：tell和say。想要发送tell消息，代理必须开通一个信道，当它通过这个信道发送知消息时，消息内容会被无线电广播到所有链接此信道的排代理。另一方面，say类型消息将其接收者限制在发送方周围指定的半径内的所有代理。
Despite being able to communicate, the simulation platform does not define a protocol to be used for communication, letting the teams free to develop their own communication protocol in order to fulfil their strategic needs. However, such definition and development is time consuming, discouraging many teams to continue to develop their agent teams in order to participate in competitions. Furthermore, the communication protocol is not the team' s goal when they first become interested by such simulation platform.
尽管有通信功能，仿真平台却没有定义用于通信的协议。团队可以根据自己的战略需求开发自己的通信协议。这样定义和改进通信协议会耗费很多时间，阻碍了团队继续改进其救援队参加竞争。此外，团队最感兴趣的是仿真平台，通信协议不是团队研究的目标。
Therefore, the RoboCup Rescue Simulation Communication Library (RCRSCS) was developed by the SUNTORI team in order to minimize this problem allowing the teams to focus their efforts of the strategic part of their teams.
因此，由SUNTORI团队开发的RoboCup救援模拟通信库(RCRSCS)是为了尽量简化这个问题，使团队能够集中精力于研究救援战略。

##### 2 Concept / 概念
In disaster environments, there are different possible ways to control the individuals responsible to perform the actual tasks on the environment. One way of performing such coordination is by delegating it to a central coordinator who is responsible to make decisions about the tasks each individual should take. This coordination structure has several advantages and disadvantages. Among the advantages is the possibility for the central coordinator to select the best task available to each individual since it knows their positions and all the tasks available in the environment; however, this coordination strategy depends heavily on communication and create a single point-of-failure in the system.
在灾难环境中，有不同的方法来控安排负责执行实际任务的个人。实现这种协调工作的一种方法是把它委托给中央协调员，由其分配对每个人应该承担的任务。这种协调结构有几个优点和缺点。优点是中央协调员可以分配给每个人最适合的任务，因为他知道所有人的位置和环境中可执行的所有任务。然而，这种协调策略很大程度上依赖于通信，并在会在系统造成单点故障。
Despite the drawbacks listed, it seems to be the most intuitive and simple form of coordination available. Therefore, the RCRSCS was implemented based on such coordination strategy in which the central location is intended to receive all the available information the individuals know from the environment and decide the task each individual should perform at each moment. Besides, the main aim of the library is to relief the teams from developing their own communication protocol before starting develop their team strategy.
尽管有列出的缺点，但这应该是最直观、最简单的协调方式。因此，RCRSCS是基于这样的协调策略来实现的，其中央协调员的任务是接收来自环境的个体所知道的所有可用信息，并决定每个个体在每个时刻应该执行的任务。RCRSCS的主要目标是在研究救援战略之前，帮助团队开发自己的通信协议。
Thus, technically speaking, platoon agents have a duty to perform actions based on the “Task Message” received from center agents. In addition, platoon agents send the obtained surrounding information (e.g. building, blockade, civilian, and so on) to other agents (platoon agents and center agents). The center agents have a duty to analyse the current situation from received information, and send “Task Message” to platoon agents as a result of their analysis. Moreover, the center agents consolidate the information in order to be able to make the best possible decision about the task a platoon agent should perform.
从技术上讲，排代理人有责任根据从中央代理接收到的“任务信息”进行行动。此外，排代理人将获得的环境信息(如建筑、封锁、市民等)发送给其他代理(排代理和中央代理)。中央代理有责任根据接收到的信息分析当前的情况，并将“任务信息”作为其分析的结果发送给排代理。此外，中心代理可以整合信息，以便能够在为一个排代理分配任务时做出最好的决定。

##### 3 Installation / 安装
In order to install the RCRSCS library (this tutorial considers the installation of RCRSCS version 1.231), it is necessary to download it from the website http://en.sourceforge.jp/projects/rcrscs/. Once downloaded, you can extract it in any directory and add the rcrscs-v1.231.jar extracted file into your build path in order to be able to use the RCRSCS communication library.
要安装RCRSCS库(本教程假定安装的时RCRSCS 1.231版),需要到http://en.sourceforge.jp/projects/rcrscs/下载它。下载后，您可以在任何目录中提取它，添加提取的rcrscs-v1.231.jar文件到你的构建路径就能使用RCRSCS通信库了。

##### 4 Usage / 使用
In order to use the RCRSCS communication library, you must:
要使用RCRSCS通信库，必须：
1. Extend the AbstractCSAgent class instead of the StandardAgent when developing a platoon or center agent;
在开发一个代理时，继承AbstractCSAgent类，而不是StandardAgent;
2. Override the following two methods:
重写以下两种方法：
```java
protected EnumSet<StandardEntityURN> getRequestedEntityURNEnum()
protected void thinking(int time, ChangeSet change, Collection<Command> heard)
```
3. Optionally, override the following method:
可选地，重写以下方法：
```java
void postConnect()
```

For example,
举个例子，
```java
public class simpleAmbulanceTeamAgent extends AbstractCSAgent<AmbulanceTeam> {
    @Override
    protected EnumSet<StandardEntityURN> getRequestedEntityURNsEnum() {
	    return EnumSet.of(StandardEntityURN.AMBULANCETEAM);
    }
    /**
     * Implements the agent specific post connection code
     */
    @Override
    protected void postConnect() {
    //TODO
    }
    /**
     * Implements the agent specific processing
     */
    @Override
    protected void thinking (int time, ChangeSet change, Collection<Command> heard) {
    //TODO
    }
}
```
There are two methods that should be used in order to enable the RCRSCS library functionalities. The methods are:
有两种方法调用RCRSCS库的功能，这些方法是：
1. setMessageChannel(int channel)
This method indicates to the RCRSCS library which channel the agent is going to use in order to send and receive messages. It should be used only once, since all the message sends and receives are going to use this channel as a reference.
该方法指示RCRSCS库，该库将使用该代理以发送和接收消息。它应该只被调用一次，因为所有的消息发送和接收都将使用这个通道。
2. addMessage(RCRSCSMessage msg)
This method adds a message into a queue. At the end of the thinking method processing, the RCRSCS library automatically sends all the messages in this queue through the channel set using the setMessageChannel method. There are several types of RCRSCSMessage available, which is described in section Message.
该方法将消息添加到消息队列中。在think方法处理结束时，RCRSCS库会自动通过setMessageChannel设置的信道发送此队列中的所有消息。有几种类型的RCRSCSMessage可用，这些会在Message章节中讲述。
The RCRSCS communication library makes available one attribute that allows the access to the heard messages from the channel set in the setMessageChannel. The attribute name is receiveMessageList and it is a list of RCRSCSMessage and it should be accessed directly in the agent code.
RCRSCS通信库提供了一个属性，允许访问从setMessageChannel方法设置的信道中获取的消息。该属性名是receiveMessageList，它是RCRSCSMessage类的列表，应该直接在代理代码中访问它。

###### 4.1 nternal Notes / 内部消息
The AbstractCSAgent extends the StandardAgent and implements the think method as required by the latter class.
AbstractCSAgent扩展了StandardAgent，并按照后者的要求实现了think方法。
```java
@Override
/**
 * Represent each step thinking .
 * (1. Receive message , 2. think , 3. send new messages)
 */
protected final void think(int time, ChangeSet changed, Collection<Command> heard() {
    super.receiveMessage(heard);
    this.thinking(time, changed, heard);
    super.sendMessage(time);
}
```
Basically, what this code does is to filter all the messages in the heard collection and add to the receiveMessageList attribute the messages received from the channel set using the setMessageChannel method. Next, it executes the implemented thinking method from the agent. Finally, it sends all the messages added to the queue during the thinking processing to the channel set using the setMessageChannel.
基本上，这段代码所做的是过滤所有收到的消息集合中的消息，并添加到receiveMessageList属性中，该属性是从setMessageChannel方法设置的信道中获取的消息。其次，代理执行实现的思维方法。最后，它将所有添加到队列中的消息发送到setMessageChannel方法设置的信道。

##### 5 Message / 消息
The RCRSCS communication library predefines three types of messages that can be sent: Information Messages, Task Messages and Report Messages.
RCRSCS通信库预定义了三种可以发送的的消息:情报消息、任务消息和报告消息。

###### 5.1 Information Message / 情报消息
###### 5.2 Task Message	/ 任务消息
###### 5.3 Report Message / 报告消息
