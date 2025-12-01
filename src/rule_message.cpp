#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <modsecurity/rule_message.h>
#include <modsecurity/rule.h>
#include <modsecurity/rule_with_actions.h>
#include <modsecurity/transaction.h>

namespace py = pybind11;

using modsecurity::Rule;
using modsecurity::RuleWithActions;
using modsecurity::RuleMessage;
using modsecurity::Transaction;

void init_rule_message(py::module &m)
{
    py::class_<RuleMessage>(m, "RuleMessage")
        .def(py::init<const RuleWithActions &, const Transaction &>())
        .def("log", (std::string (RuleMessage::*) () const) &RuleMessage::log)
        .def("log", (std::string (RuleMessage::*) (int) const) &RuleMessage::log)
        .def("log", (std::string (RuleMessage::*) (int, int) const) &RuleMessage::log)
        .def("errorLog", &RuleMessage::errorLog)
        .def("getPhase", &RuleMessage::getPhase)
        .def_readwrite("m_data", &RuleMessage::m_data)
        .def_readwrite("m_match", &RuleMessage::m_match)
        .def_readwrite("m_message", &RuleMessage::m_message)
        .def_readwrite("m_reference", &RuleMessage::m_reference)
        .def_readwrite("m_severity", &RuleMessage::m_severity)
        .def_readwrite("m_ruleId", &RuleMessage::m_ruleId)
        ;
}
