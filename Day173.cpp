/***************************************************************************************************************************************
This problem was asked by Stripe.
Write a function to flatten a nested dictionary. Namespace the keys with a period.
For example, given the following dictionary:
{
    "key": 3,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8
        }
    }
}
it should become:
{
    "key": 3,
    "foo.a": 5,
    "foo.bar.baz": 8
}
You can assume keys do not contain dots in them, i.e. no clobbering will occur.
**************************************************************************************************************************************/
def flat_dict(nested_dict,output,parent_key=''):
	for key,val in nested_dict.items():
		new_key = ".".join([parent_key,key] if parent_key else [key])
		if isinstance(val,dict):
			flat_dict(val,output,new_key)
		else:
			output[new_key] = val;
	return output

nested_dict = {
	"key": 4,
    "foo": {
        "a": 5,
        "bar": {
            "baz": 8
        }
    }
}

print(flat_dict(nested_dict,{}))
