#pragma once

/*

This is explained in much greater detail below but summerized:

My system architecture rules:

Rule 1: A function should only do what it is designed to do and nothing else.

Rule 2: A function should never trust in anything but itself.

Rule 3: Limit dependencies to what is actually needed and expected to the class and header.

Rule 4: Limit the dependencies to always go downward in hierarchy. !NEVER! upwards.

Rule 5: All dependencies has to be a general behaviour without any logic which is function/program specific.

Rule 6: Limit the exposure of your own dependencies.

Rule 7: Say: You are not fucking allowed to do that.

Rule 8: The class or function that declares the variable which allocates memory is the owner of that memory.

*/


namespace SystemArchitecture
{
	void start()
	{
		/*

		Explaining system architecture is very difficult in that it is such a broad topic. Much like all things
		in programming you can solve things in many, many ways. However, just because something "work" does not
		necessarily mean that it is "good". A game can run on 1 FPS, it still "works" but it is not "good" as it
		is unplayable.
		
		So, what is "good" code? 

		Well, regardless of the scope all functions of the program has requirements. If you are unsure of your
		requirements just ask yourself the basics. Should my game run on 5FPS? No... Of course not. What about
		60? Yes, well, in order for that to work, what do I need to do? Well, the rendering module/engine need
		at least ~17ms a frame in order to make the 60fps. What slows down the rendering process?

		And before you know it... you have a ton of requirements.

		Notice that this is usually what you encounter while coding "half way". When you begin coding a render
		engine which you have never coded before, do you really know its limits? Of course not. So how to prepare
		yourself for that?

		Let me explain from the very beginning.

		*/

		/*
		Rule 1: A function should only do what it is designed to do and nothing else.

		If a function is called "ProcessWorkingBuffer". What the fuck does that even mean? You are "processing",
		i.e. using, a buffer which is working? What? I don't even know where to begin! Do you know what the
		function does? No one does. That is why it should be completely clear what the function is doing in the
		name alone. If you are unable to name your function in what it does, then you need to split the function
		up. For example the previous function should maybe be called: "FormatMessageBuffer" which gives a hint
		in what it is doing. It is formatting a message buffer but it could include more functions in order to 
		format the message.

		*/

		/*
		
		Rule 2: A function should never trust in anything but itself.

		All inputs to a function should be treated as unreliable. You do not know where that specific code came
		from. So why should you trust it? If your function: void myFunc(aShittyClass* var, int* val);
		Always check the input parameters and return values which are used within the class. This is extremely
		important because if you do not do this. You will end up with an absurd amount of bugs which you will
		will take time to trace the origin from. This would look like this:

		void myFunc(aShittyClass* var, int* val)
		{
			if(!var || !val)
			{
				LOG("Someone fucked up.");
				return;
			}

			bool result = var->function();
			if(!bool)
			 {
				LOG("Someone really fucked up.");
				return;
			}
			//other stuff
		}

		*/

		/*
		
		Rule 3: Limit dependencies to what is actually needed and expected to the class and header.

		This rule is important in that it forces the coder to not take the convenience route. Not to
		say it is easier or better in any way but just think as to WHY.

		This has, somewhat, to be explained in steps for people not used to this idea and probably have
		only coded in objective oriented programming.

		Example 1.
		Should the class Physics include the header RenderEngine.h and does it make sense?
		No, of course not. They got nothing to do with each other.

		Example 2. 
		Should the class Monster include the header AIModule (Artificial intelligence) and does it make
		sense?
		No, although it would make sense if the AIModule included the monster and not the other way around.

		Example 3.
		Should the class Monster include the header Render.h and does it make sense?
		No. It does not make sense for a Render function to be located in the class Monster. The attributes
		of the monster has nothing to do with Render. It is easy to place it there but it does not make
		sense. An actual problem and explaination to why:

		In games each object/NPC/UI/sprite can use different models and textures. These can be defined in
		different ways in how you wish to interupt the vertex points(topology) or shaders etc. Changing these 
		GPU attributes takes time and reduces FPS. So imagine if each unit in your game is calling the Render
		function own their own to render their own unit as they go through the for-loops. Is it optimized? 
		Fuck no. It is going to lag as hell. So if the render module is organizing its own objects which is 
		registered rather than just used, it can then group up all models with the same topology or shaders.

		Voila, the convenience route might be easy at first but have significant draw backs. But does it make
		sense that a unit handle its logic on its own? Rendering itself, calculating movement patterns, making
		sounds, updating collision boxes.......... NO!
				
		*/

		/*
		
		Rule 4: Limit the dependencies to always go downward in hierarchy. !NEVER! upwards.

		
		Let's assume you have 3 functions like this:

		void FormatMessage(Message& msg)
		{
			CheckForErrors(msg);
			TranslateMsg(msg);
		}

		This rule builds on top of the rule number two. Since you are unable to trust anything that is outside
		of your function, what would happen if CheckForErrors were to be applied before calling FormatMessage?
		If it is outside FormatMessage is vurnable as TranslateMsg might crash due to bad values.
		
		How can you have dependencies that reach outside of your function so if they fail, you fail.

	
		A valid point you should be thinking is: "But I have a lot of dependencies, math library, functions i 
		would like to reuse. What about them?"

		The answer is in the next rule.
			
		*/

		/*
		
		Rule 5: All dependencies has to be a general behaviour without any logic which is 
		function/program specific.

		A mathlibrary, a game engine, ui, boost or any other sort of general module should never have program
		specific code inside of it. This means the functions will always do the same thing regardless of who
		calls it.
		
		For example, a button in the UI should not have the logic attached to itself inside the UI class. The
		logic should be reside inside the class which calls the UI button method.

		General and common functions can be used but they too have to obey all the rules. They need have a very
		limited scope in what they actually do. It might even be the case that the "common"-header has to be
		refactored into several common headers.

		*/

		/*
		
		Rule 6: Limit the exposure of your own dependencies.

		If you create a header, like this one, you should put the functions inside a namespace. That way, all
		the functions are not as easily suggested when included in other files. A header which compose of 
		hundreds of functions is not something you wish to clog the intellisense.

		Secondly, you do not wish to do includes inside the header file. It is much better with a class 
		predefinition in the header and the actual include in the .cpp-file. That way it is perfectly clear
		what is required and needed within the class. 

		*/

		/*

		Rule 7: Say: You are not fucking allowed to do that.

		Lastly and maybe most importantly... Every. Single. Thing. Has. To. Be. Justified.
		If you code using the mentality of these rules, you will pretty soon stop doing the "ugly coding".
		The "lazy and quick implementation" which _has to be reworked later_. Then, when you work with others
		in a group you will eventually see the mistakes you know not to make. You then have to stand up and say
		"You are not fucking allowed to do that." It sounds harsh but it is 110% true. If you let up with the
		rules, eventually they will come back to haunt you. You can't rewrite the system architecture once the
		program is past 60-70% complete. 

		*/

		/*
		
		Rule 8: The class or function that declares the variable which allocates memory is the owner of that memory.

		Memory leaks is a joke. It should not happen. Ever. The concept of memory allocation is extremy simple.
		If I allocate, then I will deallocate. This can happen by direct calling "new" or it can be passing a
		variable in such a way that the functions purpose is to allocate the memory. Ownership is extremely
		important. Would you ever randomly delete a pointer just because it enters your function?

		FUCK NO! Are you insane?

		For whatever reason, I've done a rather signification amount of memory leak cleanups caused by others. They
		simple don't understand the concept of ownshiper but here it is. In black and white. If you declare a
		variable, then you are responsible for it. No one else. Here is a standard example from work with an almost
		100% memoryleak occurance:

		AClass** GetAClassObjectsList();
		
		When someone called the function GetAClassObjectsList, it returned all its known AClass pointers (AClass*),
		but did so by allocation an array and passed it back as AClass**.

		The function falsely claim "Get" when it is not "getting something" it is creating something. The correct
		way would instead be:
		
		AClass** ptrsList;
		GetAClassObjectsList(ptrsList);

		Perfect.
		
		*/
	}
}