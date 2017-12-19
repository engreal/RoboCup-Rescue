# 了解ADF的结构

## ADF组件
该图显示了ADF的基本结构。代理开发人员开发红色或蓝色框架组件。
![](1ADFZuJian.png)
- 黑色的框架
这是由ADF提供的类。我们用这些类来获取信息、交流、控制行动。
- 红色的框架
这是代理开发人员开发的类。我们用这些做出决策。
- 蓝色的框架
这是代理开发人员开发的类。描述如何使用红框的组件来决定行动，（根据规则可能无法改变）

## 包图
![](2BaoTu.png)
- adf.sample
样本代理
- adf.component
开发者继承和编写的类
- adf.agent
ADF提供数据IO的类
- adf.lanucher
代理启动代码

## 开发人员编写的类
基本上，当你要开发一个代理，你应该继承包adf.component的类，然后编写代码。

### Tactics
要使用ADF对代理进行编程，请为每种类型的代理编写一个名为“Tactics”的类。基于这个类，我们将编写代理的行为。在Tactics类有五个事件处理程序。调用这些处理程序的流程如下图所示。

![](3tactisc_flow.png)
- initialize
基本的初始化
- precompute
处理预先计算
- resum
预先计算的数据
- preparete
没有预先计算时的初始化
- think
使用Module组描述每个步骤的行为决策

### ExtAction
每个Tactics使用Action类将代理的特定行为传递给服务器，ExtAction（扩展操作）描述了从抽象指令生成Action的过程。现在，假设将创建以下ExtAction。

- ActionTransport
救援(Move+Rescue+Load+Move+Unload)
- ActionFireFighting
灭火(Move+Extinguish)
- ActionRefill
补水(Move+Rest)
- ActionExtClear
清障(Move+Clear)
- ActionExtMove
移动(Move)
- ActionHeal
修复(Move+Rest)

### Modules
在ADF中，算法等是模块化的。这是为了增加代码的可重用性。
目前存在下图所示的模块。
![](4abstract-module.png)
- TargetDetector
资源分配，例如救援谁，在哪里灭火，在哪里清障
- PathPlanning
路径规划算法
- Clustering
 + StaticClustering
 分组，如地图分区
 + DynamicClustering
 集群，如消防员分组

调用这些模块的方法以确定代理的行为，如下图所示。
![](5tactics_module.png)

## ADF提供的类
除Action之外的类作为实例提供。

### Action
我们使用这个类来告诉服务器代理的具体操作。指定该类的一个实例作为think的返回值。

- common
ActionMove( {PATH} ) / ( {PATH}, X, Y)
ActionRest()
- ambulance
ActionLoad( TARGET )
ActionRescue( TARGET )
ActionUnload()
- fire
ActionExtinguish( TARGET, POWER )
ActionRefill( )
- police
ActionClear( TARGET ) / ( AGENT, VECTOR) / ( X, Y ) / ( X, Y, TARGET )

### Info
有关信息

- AgentInfo
可以获得代理信息。
- ScenarioInfo
可以获取场景的信息。
- WorldInfo
可以获得有关这个世界的信息

### PrecomputeData
它在预先计算时存储数据。它是作为预计算、恢复方法的参数传递的。
例如：
```java
precomputeData.setInteger("test", 0);
int test = precomputeData.getInteger("test");
precomputeData.setIntegerList("testList", testList);
List<Integer> testList = precomputeData.getIntegerList("testList");
```
除了Integer，它还可以存储Double·Boolean·String·EntityID。

### DevelopData
DevelopData可以获取我们想在Agent开发实验中动态变化的参数。只有使用DevelopMode启动代理程序，才可以检索该值。如果无法获得，则返回DEFAULE VALUE。您可以从代理启动时从JSON文件或参数中输入值。
例如：
```java
int test = developData.getInteger("test", 0); // (KEY, DEFAULT VALUE)
List<Integer> testList = developData.getIntegerList("testList", testList);
```
除了Integer，还可以得到Double·Boolean·String。

### ModuleManager
这个类管理Module和ExtAction的实例。
![](6module_manager.png)
例如：
```java
this.pathPlanning = moduleManager.getModule("TacticsFire.PathPlanning" , "adf.sample.module.algorithm.SamplePathPlanning");
...
this.pathPlanning = moduleManager.getModule("TacticsFire.PathPlanning");
...
this.pathPlanning = moduleManager.getModule("adf.sample.module.algorithm.MyPathPlanning"  , "adf.sample.module.algorithm.SamplePathPlanning");
...
this.pathPlanning = moduleManager.getModule("adf.sample.module.algorithm.MyPathPlanning");
...
action = moduleManager.getExtAction("TacticsFire.ActionFireFighting" , "adf.sample.extaction.ActionFireFighting").setTarget(target).calc().getAction();
...
action = moduleManager.getExtAction("TacticsFire.ActionFireFighting").setTarget(target).calc().getAction();
...
action = moduleManager.getExtAction("adf.sample.extaction.ActionFireFighting2" , "adf.sample.extaction.ActionFireFighting").setTarget(target).calc().getAction();
...
action = moduleManager.getExtAction("adf.sample.extaction.ActionFireFighting2").setTarget(target).calc().getAction();
```

### MessageManager
它管理发送给其他代理的消息并接收消息。

- CommunicationModule
该模块发送和接收消息。CommunicationModule是结构化的。虽然可以替换，但是使用ADF的开发者基本上不应该改变它。
- MessageBundle
MessageBundle是一个类，用于在MessageManager中注册要一起传送的消息类。StandardMessageBundle自动包含在内。如果包含的消息总数是16，则可以添加MessageBundle。但是，基本上只能与StandardMessageBundle进行通信。
- StandardMessageBundle
这是一个ADF标准信息。信息消息用于将每个实体的信息传递给未指定数量的代理。中央消息用于向代理传达指令。集中式消息是可以指定目的地的定向消息，但也可以作为请求发送给未指定的代理而不指定目的地。
 + information.MessageAmbulanceTeam
 + information.MessageBuilding
 + information.MessageCivilian
 + information.MessageFireBrigade
 + information.MessagePoliceForce
 + information.MessageRoad
 + centralized.CommandAmbulance
 + centralized.CommandFire
 + centralized.CommandPolice
 + centralized.CommandScout
 + centralized.MessageReport