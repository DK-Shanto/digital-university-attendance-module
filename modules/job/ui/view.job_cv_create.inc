<?php

include_once 'blade/view.job_cv_create.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">
    <div class="panel-heading">
    	Create CV
    </div>
    <div class="panel-body">
    	<div id="form">
			<form method="post" class="form-horizontal">

				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVSector">Your Proficient Sector**:</label>
	              	<div class="col-sm-6">
	              		<input type="text" name="txtCVSector" class="form-control" placeholder="Give a good title of your efficiency" required/>
				  	</div>
				</div>
		
				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVEmail">Your CV Email**:</label>
	              	<div class="col-sm-6">  		
						<input type="text" name="txtCVEmail" class="form-control" placeholder="Give your email no" required/>
					</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVPhone">Your CV Phone**:</label>
	              	<div class="col-sm-6">  		
						<input type="text" name="txtCVPhone" class="form-control" placeholder="Your Phone Number" required/>
					</div>
				</div> 

				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVProfile">Short Profile description(Max-500words)**:</label>
	              	<div class="col-sm-6">	
						<textarea name="txtCVProfile" class="form-control" rows="4" cols="50" maxlength="500" placeholder="Profile description" required></textarea>
					</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVSkillheadOne">Skill Set:</label>
	              	<div class="col-sm-6">

	              		<input type="hidden" id="skillnumber" name="skillnumber" class="form-control" value="0"/>

	              		<input type="text" name="txtCVSkillHead_0" class="form-control" placeholder="Skill header"/>	
						<textarea name="txtCVSkillDetails_0" class="form-control" rows="4" cols="50" maxlength="500" placeholder="Skill description"></textarea>

						<div id="skillset"></div>

						<div class="form-group">        
			              	<div class="col-sm-offset-2 col-sm-10">
								<input type="button" value="Add more" onclick="addskill()"/>
						    </div>
			            </div> 
					</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVTechnicalSkills">Technical Skill Set**(Max-500words)**:</label>
	              	<div class="col-sm-6">	
						<textarea name="txtCVTechnicalSkills" class="form-control" rows="4" cols="50" maxlength="500" placeholder="Such as.. XHTML,CSS,Javascript,Jquery" required></textarea>
					</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVExperienceNameOne">Experience:</label>
	              	<div class="col-sm-6">

	              		<input type="hidden" name="experiencenumber" id="experiencenumber" class="form-control" value="0"/>

	              		<input type="text" name="txtCVExperienceName_0" class="form-control" placeholder="Experience Proffession Name"/>	
	              		<input type="text" name="txtCVExperiencePost_0" class="form-control" placeholder="Experience Proffession Post"/>	
	              		<input type="text" name="txtCVExperienceTimeSpan_0" class="form-control" placeholder="Experience Proffession Time Span such as = 2007-2009"/>	
						<textarea name="txtCVExperienceDetails_0" class="form-control" rows="4" cols="50" maxlength="500" placeholder="Experience Proffession description"></textarea>

						<div id="experienceset"></div>

						<div class="form-group">        
			              	<div class="col-sm-offset-2 col-sm-10">
								<input type="button" value="Add more" onclick="addexperience()"/>
						    </div>
			            </div> 
					</div>
				</div>

				<div class="form-group">
	              	<label class="control-label col-sm-4" for="txtCVEducationInstituitionOne">Education**:</label>
	              	<div class="col-sm-6">

	              		<input type="hidden" name="educationnumber" id="educationnumber" class="form-control" value="0"/>

	              		<input type="text" name="txtCVEducationInstituition_0" class="form-control" placeholder="Experience Education Instituition" required/>	
	              		<input type="text" name="txtCVEducationSubject_0" class="form-control" placeholder="Experience Education Subject" required/>	
	              		<input type="text" name="txtCVEducationGPA_0" class="form-control" placeholder="Experience Education GPA such as = 4.0" required/>	

						<div id="educationset"></div>

						<div class="form-group">        
			              	<div class="col-sm-offset-2 col-sm-10">
								<input type="button" value="Add more" onclick="addeducation()"/>
						    </div>
			            </div> 
					</div>
				</div>
				
		        <div class="form-group">        
	              	<div class="col-sm-offset-2 col-sm-10">
						<button type="submit" value="request" name="request">Save</button>
				    </div>
	            </div> 
			</form>
		</div>
		<div id="toastME">
			Some Text Message..
		</div>
    </div>
</div>